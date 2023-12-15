////////////////////////////////////////////////////
//
// Author: Benjamin <whateveritwars@web.de>
// Copyright: 2023
//
////////////////////////////////////////////////////

int lin = 0;
int col = 10;
int c = 0;
int est = 0;
int color = 0;
int colors[7] = {1,2,3,4,5,6,7};
int k = 0;
int line[35] = {0};
int column[35] = {0};

void moveCursor(int row, int col);
void clearScreen();
int getTerminalWidth();
void tree();
void trunk();
void effects();
int main(void);
