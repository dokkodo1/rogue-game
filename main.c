#include <ncurses.h>
#include <stdio.h>

int main(void) {
    printf("Hello Rogue game\n");
    initscr();            // start ncurses mode
    noecho();             // don't echo keypresses
    cbreak();             // get keys immediately, no buffering
    keypad(stdscr, TRUE); // enable arrow keys etc.
    curs_set(0);          // hide the cursor

    mvprintw(0, 0, "@ ");  // draw the player
    refresh();             // flush to terminal

    getch();               // wait for any key

    endwin();              // restore terminal
    return 0;
}
