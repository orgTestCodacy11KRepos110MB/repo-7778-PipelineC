#pragma once

// Derive if C code is parsed+used
#ifndef __PIPELINEC__
#ifdef CELL_NEXT_STATE_IS_HW
#define CELL_NEXT_STATE_IGNORE_C_CODE
#endif
#endif

// IO types
typedef struct cell_next_state_hw_in_t{
  FSM_IN_TYPE_FIELDS_2INPUTS(int32_t, x, int32_t, y)
}cell_next_state_hw_in_t;
typedef struct cell_next_state_hw_out_t{
  FSM_OUT_TYPE_FIELDS // is_alive
}cell_next_state_hw_out_t;

// To-from bytes conversion funcs
#ifdef __PIPELINEC__
#include "cell_next_state_hw_in_t_bytes_t.h"
#include "cell_next_state_hw_out_t_bytes_t.h"
#endif
