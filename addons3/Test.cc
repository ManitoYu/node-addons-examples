#include "Test.h"

Nan::Persistent<FunctionTemplate> Test::constructor;

void Test::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  // Nan::HandleScope scope;

  // constructor
  Local<FunctionTemplate> ctor = Nan::New<FunctionTemplate>(Test::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("Test").ToLocalChecked());

  // Prototype
  Local<ObjectTemplate> proto = ctor->PrototypeTemplate();
  Nan::SetPrototypeMethod(ctor, "name", name);

  Nan::SetAccessor(proto, Nan::New("age").ToLocalChecked(), GetAge, SetAge);

  Nan::Set(target, Nan::New("Test").ToLocalChecked(), ctor->GetFunction());
}

NAN_METHOD(Test::New) {
  Test* test = new Test(info[0]->Uint32Value());
  test->Wrap(info.This());
  info.GetReturnValue().Set(info.This());
}

Test::Test(double value) : value_(value) {
}

NAN_SETTER(Test::SetAge) {
  Test* test = Nan::ObjectWrap::Unwrap<Test>(info.This());
  test->age_ = value->Uint32Value();
}

NAN_GETTER(Test::GetAge) {
  Test* test = Nan::ObjectWrap::Unwrap<Test>(info.This());
  info.GetReturnValue().Set(Nan::New(test->age_));
}
