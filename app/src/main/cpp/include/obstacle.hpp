//
// Created by 刘朝 on 2022/4/9.
//

#ifndef GAME_OBSTACLE_HPP
#define GAME_OBSTACLE_HPP

#include "engine.hpp"
#include "game_consts.hpp"
#include "util/util.hpp"

class Obstacle {
public:
    bool grid[OBS_GRID_SIZE][OBS_GRID_SIZE]; // indexed as [col][row]
    int style;  // obstacle style (currently, this specifies its color).
    int bonusRow, bonusCol;
    const static int STYLE_NULL = 0;  // a null obstacle (not displayed)

    glm::vec3 GetBoxCenter(int gridCol, int gridRow, float posY) {
        return glm::vec3(-TUNNEL_HALF_W + (gridCol + 0.5f) * OBS_CELL_SIZE, posY,
                         -TUNNEL_HALF_H + (gridRow + 0.5f) * OBS_CELL_SIZE);
    }

    glm::vec3 GetBoxSize(int gridCol, int gridRow) {
        return glm::vec3(OBS_BOX_SIZE, OBS_BOX_SIZE, OBS_BOX_SIZE);
    }

    int GetRowAt(float z) {
        return Clamp((int)floor((z + TUNNEL_HALF_H) / OBS_CELL_SIZE), 0, OBS_GRID_SIZE - 1);
    }

    int GetColAt(float x) {
        return Clamp((int)floor((x + TUNNEL_HALF_W) / OBS_CELL_SIZE), 0, OBS_GRID_SIZE - 1);
    }

    float GetMinY(float posY) { return posY - OBS_BOX_SIZE * 0.5f; }
    float GetMaxY(float posY) { return posY + OBS_BOX_SIZE * 0.5f; }

    void Reset() {
        style = STYLE_NULL;
        bonusRow = bonusCol = -1;
        memset(grid, 0, sizeof(grid));
    }

    void SetBonus(int col, int row) {
        bonusCol = col;
        bonusRow = row;
    }

    void PutRandomBonus();

    void DeleteBonus() {
        bonusCol = bonusRow = -1;
    }

    bool HasBonus() {
        return bonusRow >= 0 && bonusRow < OBS_GRID_SIZE &&
               bonusCol >= 0 && bonusCol < OBS_GRID_SIZE &&
               !grid[bonusCol][bonusRow];
    }
};

#endif //GAME_OBSTACLE_HPP
