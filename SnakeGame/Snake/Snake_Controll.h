#pragma once
#include <vector>
#include <ncurses.h>
#include "Point.h"
#include "Growth_item.h"
#include "Poison_item.h"

enum Direction{
    up = 1,
    down = -1,
    right = 2,
    left = -2
};

class Snake{
    public:
        Snake();
        void press_key();
        void moveSnake(); // 방향대로 움직이기
        bool collision_test(); // 뱀이 진행 반대방향 또는 몸에 부딫힐 때 게임 종료 
        Point return_element(int i){return snake[i];}
        Point get_last_snake(){return snake[snake.size() - 1];}
        int getSize(){return snake.size();}
        Direction getDirection() {return head_direction;}
        void setDirection(Direction d);
        void direction_Snake(); // 방향 설정
        void snake_eat_Growth(); // Growth Item을 먹게 된 경우
        void snake_eat_Poison(){ snake.pop_back(); } // Poison Item을 먹게 된 경우
    private:
        Direction head_direction; // 초기 방향 왼쪽으로
        Direction prev_direction; // 이전 방향 (해드 방향 이동을 비교할때 씀)
        int input_key;
        Point last_snake; // 끝 몸통 좌표
        std::vector<Point> snake;
};

