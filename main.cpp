#include <ncurses.h>
#include <cstring>

int main(){

  int ch, row, col;
  char buf[40];
  char name[40];

  //Initialization
  initscr();

  //No enter required
  cbreak();

  //Remove ugliness
  noecho();

  //Use arrow keys and fn keys
  keypad(stdscr, TRUE);

  //Get the display settings using MACRO 
  //weird...
  getmaxyx(stdscr, row, col);

  //Create a margin point
  col = col/6;

  //Boot up.
  mvprintw(5, col, "Daemon v1.1: What is my name?");
  move(6,col);
  refresh();

  printw("I am ");
  echo();
  getstr(buf);
  noecho();
  strcpy(name, buf);


  mvprintw(7,col, "I am %s, nice to meet you.", name);
  getch();

  endwin();



  return 0;
}
