#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <apple2.h>

#include "globals.h"
#include "menu.h"

#define MENU_LENGTH 2
#define MENU_WORD_LENGTH 9
unsigned char keyEntries[MENU_LENGTH][2] = {"C", "Q"};
unsigned char menuEntries[MENU_LENGTH][MENU_WORD_LENGTH] = {"hannel ", "uit"};

void drawMenuBar(unsigned char y) {
	static unsigned char i;
	static unsigned char x_offset;

    x_offset = 0;
	cclearxy(0, y, SIZE_X);	
    gotoxy(0,y);

    for(i = 0; i < MENU_LENGTH; i++){
        //printf("%d, %d, %d\n", i, strlen(menuEntries[i]), x_offset);
        revers(1);
        //gotoxy(x_offset, 0); cputc('1' + i);
        cputsxy(x_offset, y, keyEntries[i]);
        revers(0);
        cputsxy(x_offset + 1, y, menuEntries[i]);
        x_offset += strlen(menuEntries[i]) + 1;
    }
	revers(0);
}

void fancy_hline(unsigned char x, unsigned char y) {
    gotoxy(x,y);
    printf("<><>-------------------------------<><>\n");
}
