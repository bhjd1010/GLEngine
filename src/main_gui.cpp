
#include "main_gui.h"
#include "window.h"
#include "camera.h"

#include "imgui.h"
#include "drawable_model.h"

void MainGui::render(Window windowObj, Camera& camera,
                     std::vector<DrawableModel*> &models) {

    ImGui::SetNextWindowPos(ImVec2(0, 18));
    auto flags = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove;

    ImGui::Begin("Main Gui", nullptr, flags);

    ImGui::Text("FPS: %f", ImGui::GetIO().Framerate);
    ImGui::Separator();

    ImGui::Text("Press ~ to toggle camera mode");
    ImGui::Text("(Orbit / First Person)");
    ImGui::Separator();

    ImGui::SliderFloat("FOV", &camera.Zoom, 5.0f, 90.0f);

    auto &model = *models[m_current];

    if (ImGui::Button("Reset Camera"))
    {
        camera.Reset(model.avg_pos, -90, -10);
    }

    bool info = false;
    bool instructions = false;
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::MenuItem("Quit"))
        {
            glfwSetWindowShouldClose(windowObj.window, true);
        }

        if (ImGui::MenuItem("Model Info"))
            info = true;

        if (ImGui::MenuItem("Instructions"))
            instructions = true;

        // hack to get the menu to the right
        ImGui::EndMainMenuBar();
    }

    if (info)
        ImGui::OpenPopup("info_popup");

    if (instructions)
        ImGui::OpenPopup("instruction_popup");

    if (ImGui::BeginPopup("info_popup"))
    {
        ImGui::Text("Meshes: %d", model.mesh_count);
        ImGui::Text("Vertex Count: %d", model.vertex_count);
        ImGui::Text("Material Count: %d", model.material_count);
        ImGui::EndPopup();
    }

    if (ImGui::BeginPopup("instruction_popup"))
    {
        ImGui::Text("Orbit Mode");
        ImGui::BulletText("Click and drag to rotate");
        ImGui::BulletText("Right click and drag to pan");
        ImGui::BulletText("Scroll to move in/out");

        ImGui::Spacing();

        ImGui::Text("First Person Mode");
        ImGui::BulletText("WASD QE to move");
        ImGui::BulletText("Use mouse to aim");
        ImGui::BulletText("Scroll to zoom");
        ImGui::EndPopup();
    }

    if (ImGui::CollapsingHeader("Model Transform", ImGuiTreeNodeFlags_DefaultOpen))
    {
        ImGui::DragFloat3("Position", &*position, 0.05f);
        ImGui::DragFloat3("Rotation", &*rotation, 0.1f);
        ImGui::DragFloat3("Scale", &*scale, 0.1f);
        ImGui::Checkbox("Turntable", &turntable);
    }

    ImGui::End();

    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x, 18), 0, ImVec2(1.0f, 0));
    ImGui::Begin("Visual Options", nullptr, flags);
    if (ImGui::Checkbox("Wireframe", &wireframe))
    {
        glPolygonMode(GL_FRONT_AND_BACK, wireframe ? GL_LINE : GL_FILL);
    }
    if (ImGui::Combo("Shader", &s_current,
                     "Flat\0Blinn-Phong\0"))
    {

    }
    ImGui::End();
}
