#include <node.h>

namespace demo
{
    using v8::Exception;
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Number;
    using v8::Object;
    using v8::String;
    using v8::Value;

    void Add(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();

        if (args.Length() < 2)
        {
            isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
            return;
        }

        if (!args[0]->IsNumber() || !args[0]->IsNumber())
        {
            isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Arguments should be numbers").ToLocalChecked()));
            return;
        }

        double result = args[0].As<Number>()->Value() + args[1].As<Number>()->Value();

        args.GetReturnValue().Set(result);
    }

    void Init(Local<Object> exports)
    {
        NODE_SET_METHOD(exports, "add", Add);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Init)
}