#include <ncurses.h>

int main()
{
  initscr();

  /* Print on stdscr at present cursor position */
  printw("Hello world!");
  /* Move to (y, x) then print string */
  int x = 4;
  int y = 2;
  mvprintw(y, x, "Another hello?");
  /* Print on window win at present cursor position
     in the window */
  WINDOW *win = stdscr;
  wprintw(win, " Hello from wprintw!");
  /* Move to (y, x) relative to window
     co-ordinates and then print */
  y = 4;
  mvwprintw(win, y, x, "Goodbye world!");

  getch(); // prevent from exiting
  endwin();
  return 0;
}
