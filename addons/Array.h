#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <node.h>
#include <node_object_wrap.h>

namespace yc {

class MyArray : public node::ObjectWrap {
  public:
    static void Init(v8::Isolate* isolate);
    static void NewInstance(const v8::FunctionCallbackInfo<v8::Value>& args);

  private:
    explicit MyArray(double value);
    ~MyArray();

    static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void sort(const v8::FunctionCallbackInfo<v8::Value>& args);
    static v8::Persistent<v8::Function> constructor;

    std::vector<int> value_;
};

}

#endif // ARRAY_H
