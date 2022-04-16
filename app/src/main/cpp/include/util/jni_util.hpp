//
// Created by 刘朝 on 2022/4/9.
//

#ifndef GAME_JNI_UTIL_HPP
#define GAME_JNI_UTIL_HPP

struct JniSetup {
    jclass clazz; // activity class
    jobject thiz; // activity object
    JNIEnv *env;  // jni env
};

// Does JNI setup (if needed) and returns a struct with convenience objects.
struct JniSetup* GetJNISetup();

#endif //GAME_JNI_UTIL_HPP
