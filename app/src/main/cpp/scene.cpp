//
// Created by 刘朝 on 2022/4/9.
//

#include "include/scene.hpp"

void Scene::OnInstall() {}

void Scene::DoFrame() {}

void Scene::OnUninstall() {}

void Scene::OnStartGraphics() {}

void Scene::OnKillGraphics() {}

void Scene::OnPointerDown(int pointerId, const struct PointerCoords *coords) {}

void Scene::OnPointerUp(int pointerId, const struct PointerCoords *coords) {}

void Scene::OnPointerMove(int pointerId, const struct PointerCoords *coords) {}

bool Scene::OnBackKeyPressed() { return false; }

void Scene::OnKeyDown(int ourKeycode) {}

void Scene::OnKeyUp(int ourKeycode) {}

void Scene::OnJoy(float x, float y) {}

void Scene::OnScreenResized(int width, int height) {}

void Scene::OnPause() {}

void Scene::OnResume() {}

Scene::~Scene() {}