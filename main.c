#include <ncurses.h>

#define SCREEN_WIDTH 20
#define SCREEN_HEIGHT 20


int main(void) {
    initscr();
    printw("Hello Rogue Game!");
    cbreak();             // get keys immediately, no buffering
    noecho();             // don't echo keypresses
    keypad(stdscr, TRUE); // enable arrow keys etc.
    // curs_set(0);          // hide the cursor

    // mvprintw(10, 10, "@ ");  // draw the player
    refresh();             // flush to terminal

    getch();               // wait for any key

    endwin();              // restore terminal
    return 0;
}
