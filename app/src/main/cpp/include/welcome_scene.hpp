//
// Created by 刘朝 on 2022/4/9.
//

#ifndef GAME_WELCOME_SCENE_HPP
#define GAME_WELCOME_SCENE_HPP

#include "engine.hpp"
#include "our_shader.hpp"
#include "tex_quad.hpp"
#include "ui_scene.hpp"
#include "util/util.hpp"

class WelcomeScene : public UiScene {
protected:
    // IDs for our buttons:
    int mPlayButtonId;
    int mStoryButtonId;
    int mAboutButtonId;

    virtual void RenderBackground();

    virtual void OnButtonClicked(int id);

    void UpdateWidgetStates();

public:
    WelcomeScene();

    ~WelcomeScene();

    virtual void OnCreateWidgets();

    virtual void OnStartGraphics();

    virtual void OnKillGraphics();

    virtual void DoFrame();
};

#endif //GAME_WELCOME_SCENE_HPP
