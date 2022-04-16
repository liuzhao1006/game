//
// Created by 刘朝 on 2022/4/9.
//

#ifndef GAME_OBSTACLE_GENERATOR_HPP
#define GAME_OBSTACLE_GENERATOR_HPP

#include "engine.hpp"
#include "obstacle.hpp"

class ObstacleGenerator {
private:
    int mDifficulty;
public:
    ObstacleGenerator() {
        mDifficulty = 0;
    }

    void SetDifficulty(int dif) {
        mDifficulty = dif;
    }

    // generate a new obstacle.
    void Generate(Obstacle *result);

private:
    void GenEasy(Obstacle *result);

    void GenMedium(Obstacle *result);

    void GenIntermediate(Obstacle *result);

    void GenHard(Obstacle *result);

    void FillRow(Obstacle *result, int row);

    void FillCol(Obstacle *result, int col);
};

#endif //GAME_OBSTACLE_GENERATOR_HPP
