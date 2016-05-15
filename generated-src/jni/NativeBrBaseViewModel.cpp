// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from br_base_view_model.djinni

#include "NativeBrBaseViewModel.hpp"  // my header
#include "Marshal.hpp"
#include "NativeBrBaseViewModel.hpp"

namespace djinni_generated {

NativeBrBaseViewModel::NativeBrBaseViewModel() : ::djinni::JniInterface<::biblereader::BrBaseViewModel, NativeBrBaseViewModel>("com/thoughtsofanintrovert/brDjinni/BrBaseViewModel$CppProxy") {}

NativeBrBaseViewModel::~NativeBrBaseViewModel() = default;


CJNIEXPORT void JNICALL Java_com_thoughtsofanintrovert_brDjinni_BrBaseViewModel_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::biblereader::BrBaseViewModel>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_com_thoughtsofanintrovert_brDjinni_BrBaseViewModel_create(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::biblereader::BrBaseViewModel::create();
        return ::djinni::release(::djinni_generated::NativeBrBaseViewModel::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_com_thoughtsofanintrovert_brDjinni_BrBaseViewModel_00024CppProxy_native_1setXml(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_xml)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::biblereader::BrBaseViewModel>(nativeRef);
        ref->set_xml(::djinni::String::toCpp(jniEnv, j_xml));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated