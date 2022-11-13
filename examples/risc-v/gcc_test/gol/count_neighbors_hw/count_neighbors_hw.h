#pragma once

// Derive if C code is parsed+used
#ifndef __PIPELINEC__
#ifdef COUNT_NEIGHBORS_IS_HW
#define COUNT_NEIGHBORS_IGNORE_C_CODE
#endif
#endif

// IO types
typedef struct count_neighbors_hw_in_t{
  FSM_IN_TYPE_FIELDS_2INPUTS(int32_t, x, int32_t, y)
}count_neighbors_hw_in_t;
typedef struct count_neighbors_hw_out_t{
  FSM_OUT_TYPE_FIELDS // count
}count_neighbors_hw_out_t;

// To-from bytes conversion funcs
#ifdef __PIPELINEC__
#include "count_neighbors_hw_in_t_bytes_t.h"
#include "count_neighbors_hw_out_t_bytes_t.h"
#endif
