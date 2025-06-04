cmake_minimum_required(VERSION 3.5)
project(ament_imgui)

##################
find_package(ament_cmake)
add_subdirectory(ament_imgui)

ament_export_libraries(ament_imgui)
ament_export_libraries(glfw)
ament_export_libraries(OpenGL)
ament_export_include_directories(include include/imgui)

install(
    TARGETS ament_imgui
    DESTINATION lib
)

install(
    DIRECTORY 
        ament_imgui/include/ament_imgui 
        ament_imgui/third_party/imgui 
        ament_imgui/third_party/implot
    DESTINATION include
)

ament_package()