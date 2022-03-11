#include <napi.h>
#include "mcc_single_read.h"

// native C++ function that is assigned to 'setup' property on 'exports' object
Napi::Int setup(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  // call 'setup' function from 'mcc118_single_read.cpp' file
  // WARNING: We are passing a hard coded value for name
  int result = setup(  );

  //return new 'Napi::Int' value
  return Napi::Int::New(env, result);
}

// native C++ function that is assigned to 'single_read' property on 'exports' object
Napi::Array setup(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  // call 'setup' function from 'mcc118_single_read.cpp' file
  // WARNING: We are passing a hard coded value for name
  double* result = single_read(  );

  // create an array which we will return
  Napi::Array outres = Napi::Array::New(env, 8);

  for (int i=0; i<8; i++){
    outres[i] = result[i];
  }

  //return new 'Napi::Array' value
  return outres; // Napi::Array::Array(env, result);
}

// native C++ function that is assigned to 'finalize' property on 'exports' object
Napi::Int finalize(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  // call 'setup' function from 'mcc118_single_read.cpp' file
  // WARNING: We are passing a hard coded value for name
  int result = finalize(  );

  //return new 'Napi::String' value
  return Napi::Int::New(env, result);
}

// callback method when module is registered with Node.js
Napi::Object Init(Napi::Env env, Napi::Object exports) {
  
  exports.Set(
    Napi::String::New(env, "setup"),
    Napi::Function::New(env, setup)
  );
  
  exports.Set(
    Napi::String::New(env, "single_read"),
    Napi::Function::New(env, single_read)
  );
  
  exports.Set(
    Napi::String::New(env, "finalize"),
    Napi::Function::New(env, finalize)
  );

  return exports;
}

// register 'greet' module which calls 'Init' method
NODE_API_MODULE(daqhats, Init)
