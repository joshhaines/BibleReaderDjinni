#! /usr/bin/env bash

base_dir=$(cd "`dirname "0"`" && pwd)
cpp_out="$base_dir/generated-src/cpp"
jni_out="$base_dir/generated-src/jni"
objc_out="$base_dir/generated-src/objc"
java_out="$base_dir/generated-src/java/com/thoughtsofanintrovert/brDjinni"
java_package="com.thoughtsofanintrovert.brDjinni"
namespace="biblereader"
djinni_file="djinni/br.djinni"

./deps/djinni/src/run \
   --java-out $java_out \
   --java-package $java_package \
   --ident-java-field mFooBar \
   \
   --cpp-out $cpp_out \
   --cpp-namespace $namespace \
   \
   --cpp-optional-template boost::optional \
    --cpp-optional-header "<boost/optional.hpp>" \
    \
   --jni-out $jni_out \
   --ident-jni-class NativeFooBar \
   --ident-jni-file NativeFooBar \
   \
   --objc-out $objc_out \
   \
   --objcpp-out $objc_out \
   \
   --idl $djinni_file
