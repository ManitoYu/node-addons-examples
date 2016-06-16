#ifndef __TEST_H__
#define __TEST_H__

#include <v8.h>
#include <node_object_wrap.h>
#include <nan.h>

using namespace v8;
using namespace node;

class Test : public Nan::ObjectWrap {
  public:
    static Nan::Persistent<FunctionTemplate> constructor;
    static void Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target);

    static NAN_GETTER(GetAge);
    static NAN_SETTER(SetAge);
    static NAN_METHOD(New);
    static NAN_METHOD(name) { info.GetReturnValue().Set(Nan::New("yucong").ToLocalChecked()); }

  private:
    explicit Test(double value);
    ~Test() {}
    double value_;
    int age_;
};

#endif // __TEST_H__
