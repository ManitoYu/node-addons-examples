#include <iostream>
#include <vector>
#include <algorithm>
#include <node.h>

using std::cout;
using std::endl;
using v8::Local;
using v8::Value;
using v8::Handle;
using v8::Array;
using v8::Number;
using v8::Integer;
using v8::Function;
using v8::Null;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::String;
using v8::Object;

void callback(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<Function> cb = Local<Function>::Cast(args[0]);
  const unsigned argc = 2;
  Local<Value> argv[argc] = { String::NewFromUtf8(isolate, "yucong"), Number::New(isolate, 1) };
  cb->Call(Null(isolate), argc, argv);
}

void sort(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  std::vector<int> vec;

  for (int i = 0; i < args.Length(); i ++) {
    vec.push_back(args[i]->NumberValue());
  }

  std::sort(vec.begin(), vec.end());

  Local<Array> arr = Array::New(isolate);

  for (unsigned int i = 0; i < vec.size(); i ++) {
    arr->Set(i, Number::New(isolate, vec[i]));
  }

  args.GetReturnValue().Set(arr);

  // 输出数组
  // Handle<Array> arr = Handle<Array>::Cast(args[0]);
  // for (unsigned int i = 0; i < arr->Length(); i ++) {
  //   cout << arr->Get(i)->NumberValue() << endl;
  // }
}

void init(Local<Object> exports, Local<Object> module) {
  // NODE_SET_METHOD(module, "exports", callback);
  NODE_SET_METHOD(exports, "sort", sort);
}

NODE_MODULE(main, init)
