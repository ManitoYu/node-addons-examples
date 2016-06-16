#include <node.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

using std::cout;
using std::endl;

namespace demo {

using v8::Function;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Number;

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
}

void add(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  double value = args[0]->NumberValue() + args[1]->NumberValue();
  args.GetReturnValue().Set(Number::New(isolate, value));
}

void pid(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(Number::New(isolate, getpid()));
}

void timestamp(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  time_t t;
  time(&t);
  args.GetReturnValue().Set(Number::New(isolate, t));
}

void callback(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<Function> cb = Local<Function>::Cast(args[0]);
  const unsigned argc = 1;
  Local<Value> argv[argc] = { String::NewFromUtf8(isolate, "hello world") };
  cb->Call(Null(isolate), argc, argv);
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "hello", Method);
  NODE_SET_METHOD(exports, "add", add);
  NODE_SET_METHOD(exports, "pid", pid);
  NODE_SET_METHOD(exports, "time", timestamp);
  NODE_SET_METHOD(exports, "callback", callback);
}

NODE_MODULE(addon, init)

}
