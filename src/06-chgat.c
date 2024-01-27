/**
 * Program to output a string on the screen and modify it using attributes,
 * specifically, with the use of the chgat() function.
 */
#include <ncurses.h>

int main(int argc, char *argv[])
{
  initscr();     /* Start curses mode */
  start_color(); /* Start color functionality	*/

  /*
   * First parameter is like the code to refer to these modifications:
   *  - second parameter: text color
   *  - third parameter: bg color
   */
  init_pair(1, COLOR_CYAN, COLOR_BLACK);

  // print the string to modify
  printw("A Big string which i didn't care to type fully ");

  /*
   * First two parameters specify the position at which to start
   * Third parameter number of characters to update. -1 means till
   * end of line
   * Forth parameter is the normal attribute you wanted to give
   * to the character
   * Fifth is the color index. It is the index given during init_pair()
   * use 0 if you didn't want color
   * Sixth one is always NULL
   */
  mvchgat(0, 0, -1, A_BLINK, 1, NULL);

  refresh(); // show to screen

  getch(); // prevent from exiting

  standend(); // return to normal text mode (removes all attributes set)
  endwin();   /* End curses mode */
  return 0;
}