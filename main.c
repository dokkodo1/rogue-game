#include <stdio.h>
#include <ncurses.h>

#define WINDOW_HEIGHT   20
#define WINDOW_WIDTH    40

WINDOW *create_newwin(int height, int width, int starty, int startx) {
    WINDOW *local_win = newwin(height, width, starty, startx);
    box(local_win, 10, 10);
    wrefresh(local_win);

    return (local_win);
}

int main(void)
{
    WINDOW *my_win;

    int ch, col, row;

    initscr();
    getmaxyx(stdscr, 20, 20);
    cbreak();
    keypad(stdscr, TRUE);
    noecho();

    printw("Press q to exit\n");
    printw("col: %d\nrow:%d\n", col, row);
    refresh();
    int x = row;
    int y = col;
    my_win = create_newwin(col, row, y, x);
    wmove(my_win, x, y);
    wrefresh(my_win);

    while((ch = getch()) != 'q')
    {
        switch (ch)
        {
            case 'h':
                if (x > 0)
                    x--;
                break;
            case 'l':
                if (x < row - 1)
                    x++;
                break;
            case 'k':
                if (y > 0)
                    y--;
                break;
            case 'j':
                if (y < col - 1)
                    y++;
                break;
        }

        wmove(my_win, y, x);
        wrefresh(my_win);
    }

    endwin();
    return 0;
}
