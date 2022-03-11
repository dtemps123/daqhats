{
  "targets": [
    {
      "target_name": "daqhats",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "./lib/cJSON.c",
        "./lib/gpio.c",
        "./lib/mcc118.c",
        "./lib/mcc128.c",
        "./lib/mcc134_adc.c",
        "./lib/mcc134.c",
        "./lib/mcc152_dac.c",
        "./lib/mcc152_dio.c",
        "./lib/mcc152.c",
        "./lib/mcc172.c",
        "./lib/nist.c",
        "./lib/util.c",
        # "./tools/daqhats_check_152.c",
        # "./tools/daqhats_list_boards.c",
        # "./tools/mcc118_update_firmware.c",
        # "./tools/mcc128_update_firmware.c",
        # "./tools/mcc172_update_firmware.c",
        "./usercode/mcc118_single_read.c",
        "./usercode/index.cpp"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "./lib",
        "./include",
	      "./examples/c",
        # "./tools"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}
