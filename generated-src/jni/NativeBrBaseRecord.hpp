// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from br_base_view_model.djinni

#pragma once

#include "br_base_record.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class NativeBrBaseRecord final {
public:
    using CppType = ::biblereader::BrBaseRecord;
    using JniType = jobject;

    using Boxed = NativeBrBaseRecord;

    ~NativeBrBaseRecord();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeBrBaseRecord();
    friend ::djinni::JniClass<NativeBrBaseRecord>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/thoughtsofanintrovert/brDjinni/BrBaseRecord") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Ljava/lang/String;)V") };
    const jfieldID field_mXml { ::djinni::jniGetFieldID(clazz.get(), "mXml", "Ljava/lang/String;") };
};

}  // namespace djinni_generated