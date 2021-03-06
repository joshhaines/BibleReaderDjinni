// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from network_manager.djinni

#include "NativeNetworkListener.hpp"  // my header
#include "NativeBaseViewModel.hpp"

namespace djinni_generated {

NativeNetworkListener::NativeNetworkListener() : ::djinni::JniInterface<::biblereader::NetworkListener, NativeNetworkListener>() {}

NativeNetworkListener::~NativeNetworkListener() = default;

NativeNetworkListener::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

NativeNetworkListener::JavaProxy::~JavaProxy() = default;

void NativeNetworkListener::JavaProxy::complete(const std::shared_ptr<::biblereader::BaseViewModel> & c_view_model) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeNetworkListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_complete,
                           ::djinni::get(::djinni_generated::NativeBaseViewModel::fromCpp(jniEnv, c_view_model)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated
