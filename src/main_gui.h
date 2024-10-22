
#ifndef OPENGL_MODEL_VIEWER_IMGUI_INSPECTOR_H
#define OPENGL_MODEL_VIEWER_IMGUI_INSPECTOR_H

#include "window.h"
#include "imgui.h"
#include "camera.h"
#include "drawable_model.h"

struct MainGui {

    float position[3] = {0, 0, 0};
    float rotation[3] = {0, 0, 0};
    float scale[3] = {1, 1, 1};

    float background_color[3] = {0.89, 0.96, 0.96};

    bool wireframe = false;
    bool turntable = false;

    int m_current = 0;
    int s_current = 0;

    void render(Window windowObj, Camera &camera, std::vector<DrawableModel*> &models);
};


#endif //OPENGL_MODEL_VIEWER_IMGUI_INSPECTOR_H
