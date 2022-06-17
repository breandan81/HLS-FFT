
#include "fftBlock.h"
#include <iostream>




void fftBlock(cmpxDataInStream &in, cmpxDataOutStream &out, bool direction, bool &ovflo)
{

#pragma HLS INTERFACE axis register_mode=both register port=in
#pragma HLS INTERFACE axis register_mode=both register port=out

cmpxDataIn inArray[FFT_LENGTH];
#pragma HLS STREAM variable=inArray
cmpxDataOut outArray[FFT_LENGTH];
#pragma HLS STREAM variable=outArray
config_t config;
status_t status;
config.setDir(direction);
config.setSch(CONSERVATIVE_SCH_1024);

for (int i = 0; i < FFT_LENGTH; i++)
{
	in >> inArray[i];
}

hls::fft<param1>(inArray, outArray, &status, &config);

for (int i = 0; i < FFT_LENGTH; i++)
{
	out << outArray[i];
}
}
