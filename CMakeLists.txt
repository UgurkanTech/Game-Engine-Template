cmake_minimum_required(VERSION 3.5.0)
project(CORE VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# Add GLFW as a submodule
set(GLFW_BUILD_SHARED_LIBS OFF CACHE INTERNAL "Build shared libraries")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory(submodules/glfw)

set(IMGUI_PATH ${CMAKE_CURRENT_LIST_DIR}/submodules/imgui)
file(GLOB IMGUI_GLOB
    ${IMGUI_PATH}/imgui.h
    ${IMGUI_PATH}/imgui.cpp
    ${IMGUI_PATH}/imconfig.h
    ${IMGUI_PATH}/imgui_demo.cpp
    ${IMGUI_PATH}/imgui_draw.cpp
    ${IMGUI_PATH}/imgui_internal.h
    ${IMGUI_PATH}/imstb_rectpack.h
    ${IMGUI_PATH}/imstb_textedit.h
    ${IMGUI_PATH}/imstb_truetype.h
    ${IMGUI_PATH}/imgui_tables.cpp
    ${IMGUI_PATH}/imgui_widgets.cpp

    # specific bindings...
    ${IMGUI_PATH}/backends/imgui_impl_glfw.h
    ${IMGUI_PATH}/backends/imgui_impl_glfw.cpp
    ${IMGUI_PATH}/backends/imgui_impl_opengl3.h
    ${IMGUI_PATH}/backends/imgui_impl_opengl3.cpp
    ${IMGUI_PATH}/backends/imgui_impl_opengl3_loader.cpp)
add_library("imgui" STATIC ${IMGUI_GLOB})
target_include_directories("imgui" PUBLIC ${IMGUI_PATH})
target_link_libraries("imgui" PRIVATE glfw)

# Find the OpenGL package
find_package(OpenGL REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -static-libgcc -static-libstdc++ -static")


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/ DESTINATION ${CMAKE_BINARY_DIR}/bin/resources/)


# Create Core as a shared library
file(GLOB CORE_SRC "./Core/src/*.cpp")
add_library(Core SHARED ${CORE_SRC})

# Change output name
set_target_properties(Core PROPERTIES OUTPUT_NAME Core PREFIX "")

# Link GLFW and OpenGL to Core
target_link_libraries(Core PUBLIC imgui glfw ${OPENGL_gl_LIBRARY})

# Include GLFW's header files in Core
target_include_directories(Core PUBLIC imgui submodules/glfw/include)

target_compile_definitions(Core PRIVATE BUILDING_CORE)

# Create Editor executable
file(GLOB EDITOR_SRC "./Editor/src/*.cpp")
add_executable(Editor ${EDITOR_SRC} "./app.rc")
# Change output name
set_target_properties(Editor PROPERTIES OUTPUT_NAME Editor)
target_link_libraries(Editor Core)
target_include_directories(Editor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/CORE/src)

# Create Runtime executable
file(GLOB RUNTIME_SRC "./Runtime/src/*.cpp")
add_executable(Runtime ${RUNTIME_SRC} "./app.rc")
set_target_properties(Runtime PROPERTIES OUTPUT_NAME Runtime)
target_link_libraries(Runtime Core)
target_include_directories(Runtime PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/CORE/src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)