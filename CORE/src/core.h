// In core.h
#ifdef BUILDING_CORE
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif

#include <GLFW/glfw3.h>
#include <iostream>

// Include ImGui headers
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

CORE_API int Exec();