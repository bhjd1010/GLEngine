cmake_minimum_required(VERSION 3.22)
project(GLEngine)

set(CMAKE_CXX_STANDARD 20)

set(Glad_DIR 3rdparty/glad/cmake)
set(GLFW_DIR 3rdparty/glfw/cmake)
set(glm_DIR 3rdparty/glm/cmake/glm)

find_package(OpenGL REQUIRED)
find_package(Glad REQUIRED)
find_package(GLFW REQUIRED)
find_package(glm REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${Glad_INCLUDE_DIRS})
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${glm_INCLUDE_DIRS})
include_directories(3rdparty/plog/include)
include_directories(3rdparty/obj-loader)
include_directories(3rdparty/imgui)
include_directories(3rdparty/stb)

# set files to compile
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

file(GLOB IMGUI_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/*.cpp)
file(GLOB IMGUI_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/*.h)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir}/build)

add_executable(${PROJECT_NAME}
        ${Glad_SOURCE}
        3rdparty/stb/stb_image.h

        ${SOURCE_FILES}
        ${IMGUI_SOURCE_FILES}
        ${IMGUI_HEADERS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GLFW_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)

file(COPY ${GLFW_DLL} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
