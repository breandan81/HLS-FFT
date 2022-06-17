
#include "fftBlock.h"
#include <iostream>




void fftBlock(cmpxDataIn in[FFT_LENGTH], cmpxDataOut out[FFT_LENGTH], bool direction, bool &ovflo)
{
#pragma HLS INTERFACE depth=FFT_LENGTH port=in
#pragma HLS INTERFACE axis register_mode=both register port=in
#pragma HLS INTERFACE axis register_mode=both register port=out
config_t fft_config;
status_t fft_status;


hls::fft<param1>(in, out, &fft_status, &fft_config);
}
