#pragma once
#include "Point.h"
#include <ncurses.h>
#include <vector>
#include <random>


class Growth{
private:
    std::vector<Point> growth;
public:
    void randPosition(); // 임의의 좌표 얻기
    int getSize(){return growth.size();} // 사이즈측정
    Point return_element(int i){return growth[i];}
    void popGrowth(){growth.pop_back();}
};