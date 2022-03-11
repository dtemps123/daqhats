#include "../examples/c/daqhats_utils.h"

uint8_t address;
uint8_t channel  = 0;
uint32_t options = OPTS_DEFAULT;
double value;

char display_string[256] = "";
char c;

int result              = RESULT_SUCCESS;
int samples_per_channel = 0;
int sample_interval     = 500;  // ms
int mcc118_num_channels = mcc118_info()->NUM_AI_CHANNELS;

int     setup(int low_chan, int high_chan)
double* single_read(int low_chan, int high_chan); 
int     finalize();

