// xc7a35ticsg324-1l     Artix 7 (Arty)
// xcvu9p-flgb2104-2-i   Virtex Ultrascale Plus (AWS F1)
// xc7v2000tfhg1761-2    Virtex 7
// EP2AGX45CU17I3        Arria II GX
// 10CL120ZF780I8G       Cyclone 10 LP
// 10M50SCE144I7G        Max 10
// LFE5U-85F-6BG381C     ECP5U (LSE+Synplify)
// LFE5UM5G-85F-8BG756C  ECP5U (GHDL+Yosys+NextPNR)
#pragma PART "LFE5UM5G-85F-8BG756C"

// Most recent (and likely working) examples towards the bottom of list \/
//#include "examples/aws-fpga-dma/loopback.c"
//#include "examples/aws-fpga-dma/work.c"
//#include "examples/fosix/hello_world.c"
//#include "examples/fosix/bram_loopback.c"
//#include "examples/keccak.pc"
//#include "examples/arty/src/uart/uart_loopback_no_fc.c"
//#include "examples/arty/src/work/work.c"
//#include "examples/arty/src/fosix/main_bram_loopback.c"
//#include "examples/fir.c"
//#include "examples/arty/src/uart/uart_loopback_msg.c"
//#include "examples/arty/src/blink.c"
#include "examples/clock_crossing.c"
//#include "examples/async_clock_crossing.c"
//#include "examples/arty/src/uart_ddr3_loopback/app.c"
//#include "examples/arty/src/ddr3/mig_app.c"
//#include "examples/arty/src/eth/app.c"

/*
#include "uintN_t.h"
#pragma MAIN_MHZ main 400.0
uint64_t y;
uint64_t main(uint64_t x) //, uint64_t y)
{
  y = x + y;
  return y;
}
*/
