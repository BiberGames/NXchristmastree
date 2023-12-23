////////////////////////////////////////////////////
//
// Author: Benjamin <whateveritwars@web.de>
// Copyright: 2023
//
////////////////////////////////////////////////////

int lin = 0;
int col = 0;
int c = 0;
int s = 0;
int est = 0;
int color = 0;
int colors[7] = {1,2,3,4,5,6,7};
int k = 0;

void moveCursor(int row, int col);
void clearScreen();
int getTerminalWidth();
int getTerminalHeight();
void star();
void tree();
void trunk();
void effects();
void handleCtrlC(int signum);
int onCtrlC();
int main(void);