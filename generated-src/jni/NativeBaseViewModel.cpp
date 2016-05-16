// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from base_view_model.djinni

#include "NativeBaseViewModel.hpp"  // my header
#include "Marshal.hpp"
#include "NativeBaseViewModel.hpp"

namespace djinni_generated {

NativeBaseViewModel::NativeBaseViewModel() : ::djinni::JniInterface<::biblereader::BaseViewModel, NativeBaseViewModel>("com/thoughtsofanintrovert/brDjinni/BaseViewModel$CppProxy") {}

NativeBaseViewModel::~NativeBaseViewModel() = default;


CJNIEXPORT void JNICALL Java_com_thoughtsofanintrovert_brDjinni_BaseViewModel_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::biblereader::BaseViewModel>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_com_thoughtsofanintrovert_brDjinni_BaseViewModel_create(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::biblereader::BaseViewModel::create();
        return ::djinni::release(::djinni_generated::NativeBaseViewModel::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_com_thoughtsofanintrovert_brDjinni_BaseViewModel_00024CppProxy_native_1setXml(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_xml)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::biblereader::BaseViewModel>(nativeRef);
        ref->set_xml(::djinni::String::toCpp(jniEnv, j_xml));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated
