# Ament_imgui

This is an ament pakcage that greatly simplifies the setup required to use [Dear ImGui](https://github.com/ocornut/imgui) and [Implot](https://github.com/epezent/implot) to create a graphical interface for a ROS2 node. 

In your `CMakeLists.txt`, instead of figuring out all the include folders and source files, all you have to do is:

```
find_package(ament_imgui REQUIRED)
ament_target_dependencies(ament_imgui)
```

And, in your code, the entire setup is this:

```c++
#include <imgui_gl/imgui_gl.h>
#include <rclcpp/rclcpp.hpp>

void main()
{
    ImguiGL imgui;
    imgui.Setup( "optional path to imgui.ini file" );
    rclcpp::Rate rate(30);
    while (rclcpp::ok())
    {
        imgui.StartFrame();

        //use whatever ImGui calls you want here, directly
        ImGui::Begin("Frame");
        if(ImGui::Button("I am a button"))
            std::printf("Button pressed");
        ImGui::End();

        
        imgui.Render();
        rate.sleep();
    }
    imgui.Close();
}
```


There is, however, a catch: this package only supports using OpenGL3 and GLFW as the backend. While it would not be difficult to support other combinations (after all, the code to do so is included in the examples of Dear Imgui), I simply cannot be bothered.
