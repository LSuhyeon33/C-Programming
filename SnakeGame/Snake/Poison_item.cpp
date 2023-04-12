#include "Poison_item.h"

Point Poison::randPosition(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 58);

    int rand_Px = dis(gen);
    int rand_Py = rand_Px % 28 + 1;

    return Point(rand_Px, rand_Py);
}

void Poison::pushPoison(){
    Point p = randPosition();

    poison.push_back(p);
}
