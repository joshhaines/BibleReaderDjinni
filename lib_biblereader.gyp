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
      ],
      'xcode_settings': {
        'OTHER_CPLUSPLUSFLAGS' : ['-std=c++1y'],
      }
    }
  ],
}
