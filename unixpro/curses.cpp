#include <iostream>
#include <ncurses.h>
#include <unistd.h>
using namespace std;

#define DELAY 30000
int main() {
	
	int x = 0;
	int y = 0;
	int max_x = 0, max_y = 0;
	int next_x = 0;
	int direction = 1;

	initscr();

	noecho();
    curs_set(FALSE);

	mvprintw(5,5,"Hello World");
	refresh();
	sleep(5);

	while(1) {
		getmaxyx(stdscr, max_y, max_x);
		clear();
		mvprintw(y, x, "0");
		refresh();

		usleep(DELAY);

		next_x = x + direction;
		if(next_x >= max_x || next_x < 0) {
			direction = (-1) * direction;
		} else {
			x = x + direction;
		}
		
	}
	endwin();
}
