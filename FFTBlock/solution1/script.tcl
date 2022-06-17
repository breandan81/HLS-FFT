############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project FFTBlock
set_top fftBlock
add_files fftBlock.cpp
add_files -tb fftBlock_tb.cpp
open_solution "solution1" -flow_target vivado
set_part {xc7z010clg400-1}
create_clock -period 10 -name default
#source "./FFTBlock/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
