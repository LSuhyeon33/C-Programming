#include "Growth_item.h"

void Growth::randPosition(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 58);
    
    int x = dis(gen);
    int y = x % 28 + 1;

    growth.push_back(Point(x, y));
}
