/**
 * Program to read a and print a C file, or any files for that matter, provided
 * as an argument which make anything between the multi-line comment syntax
 * (/ * * /, I've put spaces since it will break this comment) bold.
 *
 * If the end of screen in the bottom has been reached, print out a message
 * to tell the user to press any key to keep printing the rest of the file.
 *
 * This is why this program is called "pager functionality" by Joseph.
 *
 * \note This program was really stupidly not commented well by that Joseph
 *       guy. So I'll do my best to explain what the program does.
 */
/* pager functionality by Joseph Spainhour" <spainhou@bellsouth.net> */
#include <ncurses.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // ch: holds the current character being read
  // prev: it is the character before "ch"
  // row: maximum row on the screen
  // col: maximum col on the screen
  int ch, prev, row, col;
  prev = EOF; // set prev to EOF (End Of File)
  FILE *fp;
  int y, x; // x and y will hold the current position on the screen

  // if the file is not provided then print out usage of this program instead
  if (argc != 2)
  {
    printf("Usage: %s <a c file name>\n", argv[0]);
    exit(1);
  }

  // open the file
  fp = fopen(argv[1], "r");

  // if the file does not exist, print error and exit program
  if (!fp)
  {
    perror("Cannot open input file");
    exit(1);
  }

  initscr();                      /* Start curses mode */
  getmaxyx(stdscr, row, col);     /* find the boundaries of the screen */
  while ((ch = fgetc(fp)) != EOF) /* read the file till we reach the end */
  {
    getyx(stdscr, y, x); /* get the current curser position */
    if (y == (row - 1))  /* are we are at the end of the screen
                            (as in the last row) */
    {
      printw("<-Press Any Key->"); /* tell the user to press a key */
      getch();
      clear();    /* clear the screen */
      move(0, 0); /* start at the beginning of the screen */
    }
    if (prev == '/' && ch == '*') /* If it is / and * then only
                                   * switch bold on */
                                  /* The comment above basically means to start
                                     making bold the characters after the
                                     "/*" characters */
    {
      attron(A_BOLD);          /* cut bold on */
                               /* cut? whatever he maybe meant "set" */
      getyx(stdscr, y, x);     /* get the current curser position */
      move(y, x - 1);          /* back up one space */
      printw("%c%c", '/', ch); /* The actual printing is done here */
                               /* He meant actual printing of "/*" */
    }
    else
      printw("%c", ch);
    refresh(); // show it on the screen
    if (prev == '*' && ch == '/')
      attroff(A_BOLD); /* Switch it off once we got *
                        * and then / */
    prev = ch;
  }
  endwin(); /* End curses mode */
  fclose(fp);
  return 0;
}