//
// Created by 刘朝 on 2022/4/9.
//

#ifndef GAME_OUR_SHADER_HPP
#define GAME_OUR_SHADER_HPP

#include "engine.hpp"

class OurShader : public Shader {
protected:
    GLint mColorLoc;
    GLint mTexCoordLoc;
    int mTintLoc;
    int mSamplerLoc;
    int mPointLightPosLoc;
    int mPointLightColorLoc;
public:
    OurShader();

    virtual ~OurShader();

    virtual void Compile();

    void SetTexture(Texture *t);

    void SetTintColor(float r, float g, float b);

    void EnablePointLight(glm::vec3 pos, float r, float g, float b);

    void DisablePointLight();

    virtual void BeginRender(VertexBuf *geom);

protected:
    virtual const char *GetVertShaderSource();

    virtual const char *GetFragShaderSource();

    virtual const char *GetShaderName();
};


#endif //GAME_OUR_SHADER_HPP
