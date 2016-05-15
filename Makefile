CXX = g++
CXXFLAGS = -Wall -std=c++1z

./build_ios/lib_biblereader.xcodeproj: lib_biblereader.gyp ./deps/djinni/support-lib/support_lib.gyp djinni/br.djinni
	sh ./run_djinni.sh
	./deps/gyp/gyp --depth=. -f xcode -DOS=ios --generator-output ./build_ios -Ideps/djinni/common.gypi ./lib_biblereader.gyp

ios: ./build_ios/lib_biblereader.xcodeproj
	xcodebuild -workspace BibleReader.xcworkspace \
		-scheme BibleReader \
		-configuration 'Debug' \
		-sdk iphonesimulator

clean:
	rm -rf generated-src
	rm -rf build_ios
