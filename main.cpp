#include <ncurses.h>
#include <cstring>
#include <pigpio.h>



void move_motors(){
  int ch, x_pos, y_pos, i;
  short r, c, l;

  ch    = 0;
  int pos[4] = {1450, 1350, 1190, 1320};
  int pin[4] = {21, 20, 16, 12};
  for(i=0;i<4;i++){
    gpioServo(pin[i], pos[i]);
  }

  while(ch != '\n'){
    ch = getch();

    //Reset the bolding
    c=0;
    l=-1;

    switch(ch){

    case 'q':
      pos[0] -= 10;
      gpioServo(pin[0], pos[0]);
      ch = '1';
      break;
    case 'a':
      pos[0] += 10;
      gpioServo(pin[0], pos[0]);
      ch = '1';
      break;
    case 'w':
      pos[1] -= 10;
      gpioServo(pin[1], pos[1]);
      ch = '1';
      break;
    case 's':
      pos[1] += 10;
      gpioServo(pin[1], pos[1]);
      ch = '1';
      break;
    case 'e':
      pos[2] -= 10;
      gpioServo(pin[2], pos[2]);
      ch = '1';
      break;
    case 'd':
      pos[2] += 10;
      gpioServo(pin[2], pos[2]);
      ch = '1';
      break;
    case 'r':
      pos[3] -= 10;
      gpioServo(pin[3], pos[3]);
      ch = '1';
      break;
    case 'f':
      pos[3] += 10;
      gpioServo(pin[3], pos[3]);
      ch = '1';
      break;
    }

  }


}


int main(){

  
  if(gpioInitialise()<0){
    printw("Failed");
  }


  int row, col;

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
  mvprintw(5, col, "Daemon v1.1:");

  //Press ARROWS to move my motors
  mvprintw(8,col, "Press ");
  attron(A_STANDOUT);
  printw("ARROWS");
  attroff(A_STANDOUT);
  printw(" to move my motors.");

  //Press ENTER to quit
  mvprintw(9, col, "Press ");
  attron(A_STANDOUT);
  printw("ENTER");
  attroff(A_STANDOUT);
  printw(" to quit");
  move(10,col);


  
  move_motors();



  gpioTerminate();
  endwin();


  return 0;
}
