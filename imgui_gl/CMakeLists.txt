cmake_minimum_required(VERSION 3.5)
project(imgui_gl)

##################
set(CMAKE_BUILD_TYPE "Release") 
set(CMAKE_CXX_FLAGS_RELEASE "-g -O3")




add_subdirectory(third_party/glfw)


add_library(imgui_gl 
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
    
    # fonts
    src/fonts/roboto.cpp
    src/fonts/climate-crisis.cpp
    src/fonts/revalia.cpp
)
target_include_directories(imgui_gl PUBLIC
    include 
    third_party/imgui
    third_party/imgui/backends 

    third_party/implot
)

add_dependencies(imgui_gl glfw)
target_link_libraries(imgui_gl
    glfw
    OpenGL
)

add_executable(example
   third_party/imgui/imgui_demo.cpp
   third_party/imgui/examples/example_glfw_opengl3/main.cpp)
target_link_libraries(example imgui_gl)
#
#
#install(
#    TARGETS example
#    DESTINATION share/${PROJECT_NAME}
#)
