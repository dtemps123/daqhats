#include "mcc118_single_read.h"

int setup(int low_chan, int high_chan){
	// Ensure low_chan and high_chan are valid
	if ((low_chan  >= mcc118_num_channels) || 
	    (high_chan >= mcc118_num_channels))
	{
	    fprintf(stderr, "Error: Invalid channel - must be 0 - %d.\n",
	        mcc118_num_channels - 1);
	    return -1;
	}
	if (low_chan > high_chan)
	{
	    fprintf(stderr, "Error: Invalid channels - "
	        "high_chan must be greater than or equal to low_chan\n");
	    return -1;
	}

	// Determine the address of the device to be used
	if (select_hat_device(HAT_ID_MCC_118, &address) != 0)
	{
	    return -1;
	}

	// Open a connection to each device
	result = mcc118_open(address);
	STOP_ON_ERROR(result);

	printf("\nMCC 118 single data value read example\n");
	printf("    Function demonstrated: mcc118_a_in_read\n");
	printf("    Channels: %d - %d\n", low_chan, high_chan);
	convert_options_to_string(options, display_string);
	printf("    Options: %s\n", display_string);

	return 0;
}

double* single_read(int low_chan, int high_chan){
	const int nchans = high_chan - low_chan + 1;
	double ch_vals[nchans];

	// Read a single value from each selected channel
	int idx = 0;
	for (ch = low_chan; ch <= high_chan; ch++)
	{
	    result = mcc118_a_in_read(address, ch, options, &value);
	    STOP_ON_ERROR(result);
	    ch_vals[idx] = value; idx++;
	}

	usleep(sample_interval * 1000);

	return &ch_vals;
}

int finalize(){
	result = mcc118_close(address);
    print_error(result);
	return 0;
}
