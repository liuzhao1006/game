//
// Created by 刘朝 on 2022/4/9.
//

#ifndef GAME_NATIVE_ENGINE_HPP
#define GAME_NATIVE_ENGINE_HPP

#include "common/common.hpp"

struct NativeEngineSavedState {
    bool mHasFocus;
};

class NativeEngine {
public:
    NativeEngine(struct android_app *app);

    ~NativeEngine();

    // run application until it dies
    void GameLoop();

    // returns the jni environment
    JNIEnv *GetJniEnv();

    // returns the Android app object
    android_app *GetAndroidApp();

    // returns the singleton instance
    static NativeEngine *GetInstance();

private:
    // variables to stack android lifecycle
    bool mHasFocus, mIsVisible, mHasWindow;

    // are our OpenGL objects (textures, etc) currently loaded?
    bool mHasGLObjects;

    // android api version (0 if not yet queried)
    int mApiVersion;

    // EGL stuff
    EGLDisplay mEglDisplay;
    EGLSurface mEglSurface;
    EGLContext mEglContext;
    EGLConfig mEglConfig;

    // known surface size
    int mSurfWidth, mSurfHeight;

    // android structure
    struct android_app *mApp;

    // additional saved state
    struct NativeEngineSavedState mState;

    // JNI environment
    JNIEnv *mJniEnv;

    // is this the first frame we're drawing?
    bool mIsFirstFrame;

    // initialize the display
    bool InitDisplay();

    // initialize surface. Requires display to have been initialized first.
    bool InitSurface();

    // initialize context. Requires display to have been initialized first.
    bool InitContext();

    // kill context
    void KillContext();

    void KillSurface();

    void KillDisplay(); // also causes context and surface to get killed

    bool HandleEglError(EGLint error);

    bool InitGLObjects();

    void KillGLObjects();

    void ConfigureOpenGL();

    bool PrepareToRender();

    void DoFrame();

    bool IsAnimating();

public:
    // these are public for simplicity because we have internal static callbacks
    void HandleCommand(int32_t cmd);

    bool HandleInput(AInputEvent *event);
};


#endif //GAME_NATIVE_ENGINE_HPP
