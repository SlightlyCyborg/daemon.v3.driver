#include <ncurses.h>

int main(){

  int ch;

  //Initialization
  initscr();

  //No enter required
  raw();

  //Remove ugliness
  noecho();

  //Use arrow keys and fn keys
  keypad(stdscr, TRUE);


  //Boot up.
  mvprintw(5, 5, "Daemon v1.1: What is my name?");
  move(6,5);
  refresh();

  //I can say my name
  ch = getch();
  attron(A_BOLD);
  printw("I am %c", ch);
  attroff(A_BOLD);
  refresh();

  //um..
  getch();
  printw("...", ch);
  refresh();
  getch();

  //ya..
  mvprintw(7,5,"I didn't let you finish");
  refresh();
  getch();
  endwin();	

  //reasons
  mvprintw(8,5,"..thats because I am %c", ch);
  refresh();
  getch();
  endwin();	



  return 0;
}
