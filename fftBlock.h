#ifndef FFT_BLOCK_H
#define FFT_BLOCK_H
#include "hls_fft.h"
#include <ap_fixed.h>
#include <complex>

#define FFT_INPUT_WIDTH 16
#define FFT_OUTPUT_WIDTH 16
#define FFT_LENGTH 1024
#define CONSERVATIVE_SCH_1024 0X2AB

struct param1 : hls::ip_fft::params_t {
    static const unsigned ordering_opt = hls::ip_fft::natural_order;
};
typedef hls::ip_fft::config_t<param1> config_t;
typedef ap_fixed<FFT_INPUT_WIDTH,1> data_in_t;
typedef ap_fixed<FFT_OUTPUT_WIDTH,FFT_OUTPUT_WIDTH-FFT_INPUT_WIDTH+1> data_out_t;
typedef hls::x_complex<data_in_t> cmpxDataIn;
typedef hls::x_complex<data_out_t> cmpxDataOut;
typedef hls::ip_fft::status_t<param1> status_t;





#endif
