//
// Created by 刘朝 on 2022/4/9.
//

#ifndef GAME_SIMPLEGEOM_HPP
#define GAME_SIMPLEGEOM_HPP

#include "indexbuf.hpp"
#include "vertexbuf.hpp"

class SimpleGeom {
public:
    VertexBuf *vbuf;
    IndexBuf *ibuf;

    SimpleGeom() {
        vbuf = NULL;
        ibuf = NULL;
    }

    SimpleGeom(VertexBuf *vb, IndexBuf *ib) {
        vbuf = vb;
        ibuf = ib;
    }

    SimpleGeom(VertexBuf *vb) {
        vbuf = vb;
        ibuf = NULL;
    }

    ~SimpleGeom() {
        if (vbuf) {
            delete vbuf;
        }
        if (ibuf) {
            delete ibuf;
        }
    }
};

#endif //GAME_SIMPLEGEOM_HPP
