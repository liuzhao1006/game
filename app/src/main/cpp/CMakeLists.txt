# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# build native_app_glue as a static lib
set(${CMAKE_C_FLAGS}, "${CMAKE_C_FLAGS}")
add_library(native_app_glue STATIC
        ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)

# now build app's shared lib
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -Wall -Werror")

add_definitions("-DGLM_FORCE_SIZE_T_LENGTH -DGLM_FORCE_RADIANS")

# Export ANativeActivity_onCreate(),
# Refer to: https://github.com/android-ndk/ndk/issues/381.
set(CMAKE_SHARED_LINKER_FLAGS
        "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")

add_library(game SHARED main.cpp
        anim.cpp
        ascii_to_geom.cpp
        dialog_scene.cpp
        indexbuf.cpp
        input_util.cpp
        jni_util.cpp
        native_engine.cpp
        obstacle.cpp
        obstacle_generator.cpp
        our_shader.cpp
        play_scene.cpp
        scene.cpp
        scene_manager.cpp
        sfxman.cpp
        shader.cpp
        shape_renderer.cpp
        tex_quad.cpp
        text_renderer.cpp
        texture.cpp
        ui_scene.cpp
        util.cpp
        vertexbuf.cpp
        welcome_scene.cpp)

add_subdirectory(glm)

target_include_directories(game PRIVATE
        .
        data
        ${ANDROID_NDK}/sources/android/native_app_glue)

# add lib dependencies
target_link_libraries(game
        android
        native_app_glue
        atomic
        EGL
        GLESv2
        glm
        OpenSLES
        GLESv1_CM
        log)
