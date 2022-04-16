//
// Created by 刘朝 on 2022/4/9.
//

#ifndef GAME_INDEXBUF_HPP
#define GAME_INDEXBUF_HPP

#include "common/common.hpp"

class IndexBuf {
public:
    IndexBuf(GLushort *data, int dataSizeBytes);
    ~IndexBuf();

    void BindBuffer();
    void UnbindBuffer();
    int GetCount() { return mCount; }

private:
    GLuint mIbo;
    int mCount;
};


#endif //GAME_INDEXBUF_HPP
