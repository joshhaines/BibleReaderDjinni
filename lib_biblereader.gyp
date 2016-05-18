{
  "targets": [
    {
      "target_name": "lib_biblereader_objc",
      "type": "static_library",
      "dependencies": [
        "./deps/djinni/support-lib/support_lib.gyp:djinni_objc",
      ],
      "sources": [
        "<!@(python ./deps/djinni/example/glob.py generated-src/objc  '*.cpp' '*.mm' '*.m')",
        "<!@(python ./deps/djinni/example/glob.py generated-src/cpp   '*.cpp')",
        "<!@(python ./deps/djinni/example/glob.py src '*.cpp')",
      ],
      "include_dirs": [
        "./generated-src/objc",
        "./generated-src/cpp",
        "./src/cpp",
        "/Users/admin/Documents/casablanca/Release/include",
        "/Users/admin/Documents/casablanca/Build_iOS/boost.framework/Headers",
        "/Users/admin/Documents/casablanca/Build_iOS/openssl/include",
      ],
      "libraries": [
        "/Users/admin/Documents/casablanca/Build_iOS/build.debug/libcpprest.a",
        "/Users/admin/Documents/casablanca/Build_iOS/openssl/lib/libcrypto.a",
        "/Users/admin/Documents/casablanca/Build_iOS/openssl/lib/libssl.a",
        "/usr/local/Cellar/libiconv/1.14/lib/libiconv.dylib",
      ],
      'xcode_settings': {
        'OTHER_CPLUSPLUSFLAGS' : ['-std=c++1y'],
      }
    }
  ],
}
