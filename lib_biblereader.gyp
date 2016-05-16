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
        "/usr/local/Cellar/boost/1.60.0_2/include",
        "/usr/local/Cellar/cpp-netlib/0.12.0_1/include",
        "/usr/local/Cellar/asio/1.10.6/include",
        "/usr/local/opt/openssl/include"
      ],
      "libraries": [
        "/usr/local/Cellar/cpp-netlib/0.12.0_1/lib/libcppnetlib-uri.a",
        "/usr/local/Cellar/openssl/1.0.2h_1/lib/libcrypto.a",
        "/usr/local/Cellar/boost/1.60.0_2/lib/libboost_system.a",
        "/usr/local/Cellar/cpp-netlib/0.12.0_1/lib/libcppnetlib-client-connections.a",
        "/usr/local/Cellar/openssl/1.0.2h_1/lib/libssl.a",
        "/usr/local/Cellar/cpp-netlib/0.12.0_1/lib/libcppnetlib-server-parsers.a"
      ],
      'xcode_settings': {
        'OTHER_CPLUSPLUSFLAGS' : ['-std=c++1y'],
      }
    }
  ],
}
