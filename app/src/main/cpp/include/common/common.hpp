//
// Created by 刘朝 on 2022/4/9.
//

#ifndef GAME_COMMON_HPP
#define GAME_COMMON_HPP

extern "C" {
    #include <EGL/egl.h>
    #include <GLES2/gl2.h>
    #include <jni.h>
    #include <errno.h>
    #include <android/sensor.h>
    #include <android/log.h>
    #include <android_native_app_glue.h>
    #include <unistd.h>
    #include <stdlib.h>
}

// 引入glm库
#include "../../glm/glm.hpp"
#include "../../glm/gtc/type_ptr.hpp"
#include "../../glm/gtc/matrix_transform.hpp"
#include "../../glm/glm.hpp"
#include "../../glm/gtc/type_ptr.hpp"
#include "../../glm/gtc/matrix_transform.hpp"

#define DEBUG_TAG "syd:Game"
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, DEBUG_TAG, __VA_ARGS__))
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, DEBUG_TAG, __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, DEBUG_TAG, __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, DEBUG_TAG, __VA_ARGS__))
#define ABORT_GAME { LOGE("*** GAME ABORTING."); *((volatile char*)0) = 'a'; }
#define DEBUG_BLIP LOGD("[ BLIP ]: %s:%d", __FILE__, __LINE__)
#define MY_ASSERT(cond) { if (!(cond)) { LOGE("ASSERTION FAILED: %s", #cond); \
   ABORT_GAME; } }

#define BUFFER_OFFSET(i) ((char*)NULL + (i))

#include "our_key_codes.hpp"

#endif //GAME_COMMON_HPP
