#include <ncurses.h>
#include "Snake_window.h"
#include "Snake_Controll.h"
#include "Growth_item.h"
#include "Poison_item.h"

int main(){
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    init_pair(2, COLOR_RED, COLOR_RED);
    init_pair(3, COLOR_BLACK, COLOR_BLACK);
    //snake color
    init_pair(4, COLOR_RED, COLOR_WHITE);

    WINDOW* snake_map; // 게임판 size:(60 x 30)
    snake_map = newwin(32,62,0,0);
    wborder(snake_map,'|','|','-','-','+','+','+','+');
    mvwprintw(snake_map, 0, 25, "snake map");
    wrefresh(snake_map);

    Snake_Map Smap;
    Smap.print_map(snake_map);    
    Snake snake;
    Smap.snake_map(snake);
    Smap.print_map(snake_map);
    Growth growth; // Growth_item
    Poison poison; // Poison_item

    snake.setDirection(left);
    int count = 0;

    while (true)
    {
        Smap.clear_map();
        snake.press_key();
        if((Smap.wall_collision_test(snake.return_element(0)) == false) || (Smap.length_test(snake) == false) || (snake.collision_test() == false)){
            break;
        }
        if(count % 50 == 0){
            Smap.growth_item_map(growth);
            Smap.poison_item_map(poison);
        }
        Smap.check_poison_item_snake(snake, poison);
        Smap.check_growth_item_snake(snake, growth);
        Smap.snake_map(snake);
        Smap.print_map(snake_map);
        count++;
    }
    
    getch();
    endwin();

    return 0;
}