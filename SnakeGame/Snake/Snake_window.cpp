#include "Snake_window.h"

void Snake_Map::snake_map(Snake snake){
    for(int i = 1; i < snake.getSize(); i++){
        int coor_x = snake.return_element(i).getX();
        int coor_y = snake.return_element(i).getY();
        map[coor_y][coor_x] = 4;
    }
    int coor_x = snake.return_element(0).getX();
    int coor_y = snake.return_element(0).getY();
    map[coor_y][coor_x] = 3;
}

void Snake_Map::growth_item_map(Growth &growth){
    growth.randPosition();
    int coor_x = growth.return_element(time).getX();
    int coor_y = growth.return_element(time).getY();
    if(map[coor_y][coor_x] == 0){
        map[coor_y][coor_x] = 5;
    }
}

void Snake_Map::poison_item_map(Poison &poison){
    poison.pushPoison();
    
    int x = poison.return_element(time).getX();
    int y = poison.return_element(time).getY();
    if(map[y][x] == 0){
        map[y][x] = 6;
    }
    time++;
}

void Snake_Map::check_poison_item_snake(Snake &snake, Poison &poison){
    Point head = snake.return_element(0); // 스네이크 머리의 좌표
    Point nth_poison = poison.return_element(time - 1); // n번째 poison의 좌표
    if(head == nth_poison){
        snake.snake_eat_Poison();
    }
}

void Snake_Map::check_growth_item_snake(Snake &snake, Growth &growth){
    Point head = snake.return_element(0); // 스네이크 머리의 좌표
    Point nth_growth = growth.return_element(time - 1); // n번째 growth의 좌표
    
    if(head == nth_growth){
        snake.snake_eat_Growth();
    }
}

void Snake_Map::print_map(WINDOW* snake_map){
    for(int i = 1; i <= 30; i++){
        for(int j = 1; j <= 60; j++){
            if(map[i-1][j-1] == 6){
                wattron(snake_map, COLOR_PAIR(4));
                mvwprintw(snake_map, i, j,"%c", 'P');
            }else if(map[i-1][j-1] == 5){
                wattron(snake_map, COLOR_PAIR(4));
                mvwprintw(snake_map, i, j,"%c", 'G');
            }else if(map[i-1][j-1] == 3){
                wattron(snake_map, COLOR_PAIR(4));
                mvwprintw(snake_map, i, j,"%c", 'M');
            }else if(map[i-1][j-1] == 4){
                wattron(snake_map, COLOR_PAIR(4));
                mvwprintw(snake_map, i, j, "%c", 'O');
            }else if(map[i-1][j-1] == 2){
                wattron(snake_map, COLOR_PAIR(2));
                mvwprintw(snake_map, i, j, "%d", map[i-1][j-1]);
            }else if(map[i-1][j-1] == 1){
                wattron(snake_map, COLOR_PAIR(3));
                mvwprintw(snake_map, i, j, "%d", map[i-1][j-1]);
            }else{
                wattron(snake_map, COLOR_PAIR(1));
                mvwprintw(snake_map, i, j, "%d", map[i-1][j-1]);
            }   
        }
    }
    wrefresh(snake_map);
}

void Snake_Map::clear_map(){
    if(count % 50 == 0){
        for(int i = 1; i <= 28; i++){
            for(int j = 1; j <= 58; j++){
                map[i][j] = 0;
            }
        }
    }
    else{
        for(int i = 1; i <= 28; i++){
            for(int j = 1; j <= 58; j++){
                if((map[i][j] != 5) && (map[i][j] != 6)) map[i][j] = 0;   
            }
        }
    }
    count++;
}

bool Snake_Map::wall_collision_test(Point head){
    if(map[head.getY()][head.getX()] == 1){
        return false;
    }
    return true;
}

bool Snake_Map::length_test(Snake snake){
    if(snake.getSize() <= 2){
        return false;
    }
    return true;
}