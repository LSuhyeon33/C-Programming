#pragma once
#include "Point.h"
#include <ncurses.h>
#include <vector>
#include <random>
#include <iostream>

class Poison{
private:
    std::vector<Point> poison;
public:
    // void randPosition(); // 임의의 좌표 얻기
    Point randPosition();
    int getSize(){return poison.size();} // 사이즈측정
    Point return_element(int i){ return poison[i];}
    void pushPoison();
    void popPoison(){poison.pop_back();}
};