#include <cstdlib>
#include <ctime>
#include <cstring>
#include <utility>
#include <algorithm>
#include <cmath>
#ifndef AI_H
#define AI_H
#include "game.h"

const int Layer = 5;
//weight layer

const int acc = 4;
//weight accuracy

const int dis = 10;
//move compute distance

const float threshold = 0.8;
//weight threshold

class game;

class ai{
private:
    int weight[Layer][8][8][8][8][acc];
    //[layer][from_x][from_y][to_x][to_y][weight]
    //-5.000 ~ 4.999
    //normally 0.000 ~ 9.999, -5.000 to get negative weight
    float value[8][8];
    //value of each point
    float tmp[8][8];
public:
    ai(bool init);
    ~ai();
    void set_value(game *v);
    bool run(game *v, bool sh);
    friend class train;
    void set_weight();
};

#endif
