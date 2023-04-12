#include "Snake_Controll.h"
#include <iostream>

Snake::Snake(){
    // 초기 설정 중앙에 길이 3의 뱀 출현
    snake.push_back(Point(30, 15));
    snake.push_back(Point(31, 15));
    snake.push_back(Point(32, 15));
}

void Snake::press_key(){
    prev_direction = head_direction;
    last_snake = get_last_snake();
    input_key = getch();
    direction_Snake();
    if(prev_direction != head_direction) moveSnake();
    else{ 
        halfdelay(1);
        moveSnake();
    }
}

void Snake::moveSnake(){
    for(int i = snake.size() - 1; i >= 1 ; i--){
        snake[i] = snake[i-1];
    }

    int coor_x = snake[0].getX();
    int coor_y = snake[0].getY();

    switch(head_direction){
        case up :
            snake[0].setY(coor_y - 1);
            break;
        case down :
            snake[0].setY(coor_y + 1);
            break;
        case right:
            snake[0].setX(coor_x + 1);
            break;
        case left :
            snake[0].setX(coor_x - 1);
            break;
    }
}

bool Snake::collision_test(){
    for(int i = 1; i < snake.size(); i++){
        if(snake[0] == snake[i]) {
            return false;
        }
    }
    return true;
}

void Snake::setDirection(Direction d){
    head_direction = d;
}

void Snake::direction_Snake(){
    switch(input_key){
        case KEY_UP :
            setDirection(up);
            break;
        case KEY_DOWN :
            setDirection(down);
            break;
        case KEY_RIGHT:
            setDirection(right);
            break;
        case KEY_LEFT :
            setDirection(left);
            break;
    }
}

void Snake::snake_eat_Growth(){
    snake.push_back(last_snake);
}