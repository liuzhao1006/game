//
// Created by 刘朝 on 2022/4/9.
//

#ifndef GAME_TEXTURE_HPP
#define GAME_TEXTURE_HPP

#include "common/common.hpp"
class Texture {
private:
    GLuint mTextureH;

public:
    inline Texture() {
        mTextureH = 0;
    }

    // Initialize from raw RGB data. If hasAlpha is true, then it's 4 bytes per pixel
    // (RGBA), otherwise it's interpreted as 3 bytes per pixel (RGB).
    void InitFromRawRGB(int width, int height, bool hasAlpha, const unsigned char *data);
    void Bind(int unit);
    void Unbind();
};


#endif //GAME_TEXTURE_HPP
