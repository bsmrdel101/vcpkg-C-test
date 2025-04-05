cmake_minimum_required(VERSION 3.10)
project(VCPKG_TEST C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_PREFIX_PATH "C:/vcpkg/installed/x64-windows/share" CACHE STRING "Path to vcpkg installed packages")

add_executable(app src/main.c)

# Packages
find_package(SDL3 REQUIRED CONFIG)
find_package(SDL3_image REQUIRED CONFIG)

target_link_libraries(app PRIVATE SDL3::SDL3)
target_link_libraries(app PRIVATE $<IF:$<TARGET_EXISTS:SDL3_image::SDL3_image-shared>,SDL3_image::SDL3_image-shared,SDL3_image::SDL3_image-static>)
