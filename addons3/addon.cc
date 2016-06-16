#include <v8.h>
#include <node.h>
#include <nan.h>
#include <iostream>
#include "Test.h"

using namespace v8;
using namespace node;
using namespace std;

NAN_MODULE_INIT(init) {
  Test::Initialize(target);
}

NODE_MODULE(addon, init)
