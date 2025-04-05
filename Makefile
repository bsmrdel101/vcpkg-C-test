all: dev run

dev:
	cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_BUILD_TYPE=Debug
	cmake --build build --config Debug

prod:
	cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_BUILD_TYPE=Release
	cmake --build build --config Release

run:
	./build/Debug/app.exe

clean:
	rm -rf build
