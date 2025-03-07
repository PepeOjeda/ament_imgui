cmake_minimum_required(VERSION 3.5)
project(ament_imgui)

##################
set(CMAKE_BUILD_TYPE "None") 
set(CMAKE_CXX_FLAGS "-std=c++17 -g -O2 ${CMAKE_CXX_FLAGS}")



find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

include_directories(
    include 
    third_party/imgui
    third_party/imgui/backends 

    third_party/implot
)

add_subdirectory(third_party/glfw)


add_library(ament_imgui 
    src/imgui.cpp
    third_party/imgui/backends/imgui_impl_glfw.cpp
    third_party/imgui/backends/imgui_impl_opengl3.cpp
    third_party/imgui/imgui_draw.cpp
    third_party/imgui/imgui_tables.cpp
    third_party/imgui/imgui_widgets.cpp
    third_party/imgui/imgui.cpp
    third_party/imgui/misc/cpp/imgui_stdlib.cpp

    third_party/implot/implot.cpp
    third_party/implot/implot_items.cpp
)


add_dependencies(ament_imgui glfw)
ament_target_dependencies(ament_imgui rclcpp)
target_link_libraries(ament_imgui
glfw
OpenGL
)

ament_export_libraries(ament_imgui)
ament_export_libraries(glfw)
ament_export_libraries(OpenGL)
ament_export_include_directories(include include/imgui)

install(
    TARGETS ament_imgui
    DESTINATION lib
)

install(
    DIRECTORY include/ament_imgui third_party/imgui third_party/implot
    DESTINATION include
)





#add_executable(example
#    third_party/imgui/imgui_demo.cpp
#    third_party/imgui/examples/example_glfw_opengl3/main.cpp)
#add_dependencies(example imgui)
#target_link_libraries(example imgui)
#
#
#install(
#    TARGETS example
#    DESTINATION share/${PROJECT_NAME}
#)

ament_package()