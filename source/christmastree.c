////////////////////////////////////////////////////
//
// Author: Benjamin <whateveritwars@web.de>
// Copyright: 2023
//
////////////////////////////////////////////////////

#include <switch.h>
#include <stdio.h>

#include "christmastree.h"

void moveCursor(int row, int col) {
    printf("\033[%d;%dH", row, col);
}

void clearScreen() {
    printf("\e[1;1H\e[2J");
}

int getTerminalWidth() {
    return 83;
}

int getTerminalHeight() {
    return 10;
}

void star() {
    printf("\033[0;33m");
    moveCursor(lin-3, col-3);
    printf("  .  \n");
    moveCursor(lin-2, col-3);
    printf(".....\n");
    moveCursor(lin-1, col-3);
    printf(" . . \n");
    moveCursor(lin, col-3);
    printf("\033[0m");
}

void tree() {
    for(int i=1; i<=20; i+=2) {
        moveCursor(lin, col-1);
        for(int j=1; j<=i; j++) {
            printf("\033[32;1m");
            putchar('*');
            printf("\033[0m");
        }
        lin++;
        col--;
    }
}

void trunk() {
    for(int i=1; i<=2; i++) {
        moveCursor(lin++, c-1);
        printf("\033[0m\033[33mmWm\033[0m\n");
    }
}

void effects() {
    int li = (rand() % 9) + 3;
    int start = c - li + 2;
    int co = rand() % (li-2) * 2 + 1 + start;

    k = rand() % 2;

    if(k == 0) {
        color = rand() % 6;
        printf("\e[0;3%dm", colors[color]);
        moveCursor(li + (lin - 15), co);
        putchar('o');
    }
    else {
        moveCursor(li + (lin - 15), co);
        printf("\033[32;1m");
        putchar('*');
        printf("\033[0m");
    }

    if(s < 10) {
        moveCursor(getTerminalHeight() / 2 + 3, getTerminalWidth() / 2 - 3);
        printf("\033[0;33m");
        printf(". . .\n");
        s++;
    }
    else {
        moveCursor(getTerminalHeight() / 2 + 3, getTerminalWidth() / 2 - 3);
        printf("\033[0;33m");
        printf(".....\n");
        s = 0;
    }
	usleep(100000);
}

int main(void) {
	consoleInit(NULL);
	padConfigureInput(1, HidNpadStyleSet_NpadStandard);
	PadState pad;
    padInitializeDefault(&pad);

    lin = getTerminalHeight();
    col = getTerminalWidth() / 2;
    c = col - 1;
    est = c - 2;
    color = 0;
	
	star();
    tree();
    trunk();
	while(appletMainLoop()) {
		padUpdate(&pad);

        u64 kDown = padGetButtonsDown(&pad);

        if (kDown & HidNpadButton_Plus)
            break;
		
		effects();
		consoleUpdate(NULL);
	}
	
	consoleExit(NULL);
	return 0;
}
