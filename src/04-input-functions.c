/**
 * Program to asks a user for string input then print it back.
 */
#include <ncurses.h> /* ncurses.h includes stdio.h */
#include <string.h>

int main()
{
  /* message to be appeared on the screen */
  char msg[] = "Enter a string: ";
  char str[80];

  /* to store the number of rows and
     the number of columns of the screen */
  int row, col;

  initscr();                  // start curses mode
  getmaxyx(stdscr, row, col); // get the number of rows and columns

  /* print the message at the center of the screen */
  mvprintw(row / 2, (col - strlen(msg)) / 2, "%s", msg);
  getstr(str);

  mvprintw(LINES - 2, 0, "You Entered: %s", str);

  getch();
  endwin(); // end curses mode

  return 0;
}