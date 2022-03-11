#ifndef MCC118SINGLEREAD
#define MCC118SINGLEREAD

#include "../examples/c/daqhats_utils.h"

uint8_t address;
uint8_t ch  = 0;
uint32_t options = OPTS_DEFAULT;
double value;

char display_string[256] = "";
char c;

int result              = RESULT_SUCCESS;
int samples_per_channel = 0;
int sample_interval     = 500;  // ms
int mcc118_num_channels = 0;

int     setup();//uint8_t low_chan, uint8_t high_chan);
double* single_read();//uint8_t low_chan, uint8_t high_chan); 
int     finalize();
int     main();

#endif // MCC118SINGLEREAD