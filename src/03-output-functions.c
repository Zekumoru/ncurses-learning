#include <ncurses.h> /* ncurses.h includes stdio.h */
#include <string.h>

int main()
{
  /* message to be appeared on the screen */
  char msg[] = "Just a string";
  /* to store the number of rows and
     the number of columns of the screen */
  int row, col;

  initscr(); // start curses mode

  /* get the number of rows and columns */
  getmaxyx(stdscr, row, col);

  /* print the message at the center of the screen */
  mvprintw(row / 2, (col - strlen(msg)) / 2, "%s", msg);

  /* print following messages on the bottom-left of the screen */
  mvprintw(row - 2, 0, "This screen has %d rows and %d columns\n", row, col);
  printw("Try resizing your window(if possible) and then run this program again");

  refresh(); // write to the actual screen

  getch();  // prevent from exiting
  endwin(); // end curses mode

  return 0;
}