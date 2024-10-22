![image](https://github.com/user-attachments/assets/288c1ccf-24c2-41b5-996e-a78c030e4a26)

# GLEngine
A C++/OpenGL mesh viewer for OBJ format models.
## Introduction
GLEngine is an open-source library designed to view and edit 3D models in common formats. Written in C++20, this library leverages the power of OpenGL to provide real-time rendering capabilities and a robust framework for interacting with 3D assets.
## Features
Under development, new features are on the way

**Camera:**

- WASD for close-far and left-right movement
- Mouse drag for rotation
- Mouse scroll for zoom

**Rendering:**

- Constant ambient light
- Blinn-Phong

**Model:**

- OBJ file for mesh vertices, normals and UVs
- MTL file for materials

## Build & Run

- `mkdir build && cd build`
- `cmake ..`

## Resources

### 3rd Party Libraries

- Glad, Multi-Language GL/GLES/EGL/GLX/WGL Loader-Generator based on the official specs, https://glad.dav1d.de/
- GLFW, an Open Source, multi-platform library for OpenGL, OpenGL ES and Vulkan development on the desktop, https://www.glfw.org/
- GLM, a header only C++ mathematics library for graphics software based on the OpenGL Shading Language (GLSL) specifications, https://github.com/g-truc/glm
- Plog, portable, simple and extensible C++ logging library, https://github.com/SergiusTheBest/plog
- OBJ-Loader, a simple, header only, .obj model file loader, https://github.com/Bly7/OBJ-Loader
- stb, single-file public domain (or MIT licensed) libraries for C/C++, https://github.com/nothings/stb
