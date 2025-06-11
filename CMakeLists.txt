cmake_minimum_required(VERSION 3.5)
project(ament_imgui)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Release")

##################
find_package(ament_cmake)
add_subdirectory(imgui_gl)

ament_export_libraries(imgui_gl)
ament_export_libraries(glfw)
ament_export_libraries(OpenGL)
ament_export_include_directories(include include/imgui)

install(
    TARGETS imgui_gl
    DESTINATION lib
)

install(
    DIRECTORY 
        imgui_gl/include/imgui_gl 
        imgui_gl/third_party/imgui 
        imgui_gl/third_party/implot
    DESTINATION include
)

ament_package()