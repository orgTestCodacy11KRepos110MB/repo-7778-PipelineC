// Modified version of original MNIST example to support 
// pixel memory being shared/loaded over ethernet 
// and predicitions being sent back over ethernet

uint32_t inference_fsm_basic()
{
  static uint32_t i; // Label
  static uint32_t j; // Per image pixel
  // Pixels are shared with logic to load over ethernet
  // Weights, biases, activations
  static float weight[MNIST_LABELS*MNIST_IMAGE_SIZE] = 
    #include "trained/weights.c"
  ;
  static float bias[MNIST_LABELS] = 
    #include "trained/biases.c"
  ;
  static float activation[MNIST_LABELS]; // init to zeros
  
  // Loop computing activation for each label
  for(i = 0; i < MNIST_LABELS; i+=1) 
  {
      float b = bias_RAM_SP_RF_0(i, 0.0, 0); // ROM lookup
      activation[i] = b; // Array write
      for(j = 0; j < MNIST_IMAGE_SIZE; j+=1)
      {
        __clk(); // Combinatorial logic dividing marker
        pixel_t p = pixel_mem_read(j); // RAM lookup
        float scaled_pixel = (float)p * (1.0/255.0); // FP mul
        float w = weight_RAM_SP_RF_0(i*MNIST_IMAGE_SIZE + j, 0.0, 0); // ROM lookup
        float act_inc = w * scaled_pixel; // FP mul
        activation[i] = activation[i] + act_inc; // Array RMW (FP add)
      }
  }
  
  __clk(); // Combinatorial logic dividing marker
  // Find maximally activated neuron
  uint32_t max_act_label;
  float max_act = FLOAT_MIN;
  uint32_t i;
  for(i=0; i<MNIST_LABELS; i+=1)
  {
    float act_i = activation[i]; // Array lookup
    if(act_i > max_act) // FP compare
    {
      max_act = act_i;
      max_act_label = i;
    }
  }  
  return max_act_label;
}
// Derived fsm from inference func
#include "inference_fsm_basic_FSM.h"
// Wrap up inference FSM as top level
MAIN_MHZ(inference_fsm_basic_wrapper, NN_CLOCK_MHZ)
void inference_fsm_basic_wrapper()
{
  inference_fsm_basic_INPUT_t i;
  // Run repeatedly
  i.input_valid = 1; 
  i.output_ready = 1;
  inference_fsm_basic_OUTPUT_t o = inference_fsm_basic_FSM(i);

  // Assemble output prediction to write into fifo
  pred_resp_t resp[1];
  resp[0].pred = o.return_output;
  
  // Get count of how many nanosec between predictions
  static uint32_t nanosec_counter;
  resp[0].nanosec_since = nanosec_counter;
  nanosec_counter += (uint32_t)(1000.0/NN_CLOCK_MHZ);
  if(o.output_valid)
  {
    nanosec_counter = 0;
  }

  // Write output predictions into fifo
  outputs_fifo_write_t output_write = outputs_fifo_WRITE_1(resp, o.output_valid);
}
