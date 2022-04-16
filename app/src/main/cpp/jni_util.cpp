//
// Created by 刘朝 on 2022/4/9.
//

#include "include/common/common.hpp"
#include "include/util/jni_util.hpp"
#include "include/native_engine.hpp"

static struct JniSetup _jni_setup = {0};

struct JniSetup* GetJNISetup() {
    if (!_jni_setup.env) {
        _jni_setup.env = NativeEngine::GetInstance()->GetJniEnv();
        _jni_setup.thiz = NativeEngine::GetInstance()->GetAndroidApp()->activity->clazz;
        _jni_setup.clazz = _jni_setup.env->GetObjectClass(_jni_setup.thiz);
    }
    return &_jni_setup;
}