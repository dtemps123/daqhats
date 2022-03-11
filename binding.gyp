{
  "targets": [
    {
      "target_name": "daqhats",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "./usercode/mcc118_single_read.cpp",
        "./usercode/index.cpp"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "./include",
        "./lib",
	"./examples/c/"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}
