/**
 * Program to get a character from a user then print it out.
 * Handles also special inputs such as F1.
 */
#include <ncurses/ncurses.h>

int main()
{
  int ch;

  /* Start curses mode */
  initscr();
  /* Line buffering disabled,
    basically don't wait for newline for inputs,
    process them immediately	*/
  raw();
  /* Allow arrow, F1, F2, etc. inputs */
  keypad(stdscr, TRUE);
  /* Don't echo(), i.e. write input to screen, while we do getch */
  noecho();

  printw("Type any character to see it in bold\n");

  /* If raw() hadn't been called
    we have to press enter before it
    getch to the program. */
  ch = getch();

  /* Without keypad enabled this will not get to us either.
    Also, without noecho() some ugly escape
    characters might have been printed on screen */
  if (ch == KEY_F(1))
  {
    printw("F1 Key pressed");
  }
  else
  {
    printw("The pressed key is ");
    attron(A_BOLD);
    printw("%c", ch);
    attroff(A_BOLD);
  }

  /* Print it on to the real screen
    since currently it's on a "virtual screen", i.e. RAM */
  refresh();
  /* Stop the program from exiting until a user presses a key */
  getch();
  /* End curses mode */
  endwin();

  return 0;
}
