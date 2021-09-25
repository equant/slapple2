#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <apple2.h>
#include <peekpoke.h>

#include "globals.h"
#include "menu.h"
#include "apple2idiot.h"

unsigned char i = 0;
char pause_char;
char channel_name[22];
unsigned int address_offset = 0;

void main(void)
{
    unsigned char key;
    clrscr();

    while (key != 'Q') {    // Last menu item should be Quit
        drawMenuBar(0);
        //gotoxy(0,2);
        //printf("Country: %s    City:%s", country_code, city);
        gotoxy(0,SIZE_Y-1);
        printf("Menu Selection:");
        cursor(1);
        key = toupper(cgetc());
        //gotoxy(0,SIZE_Y-3);
        //printf("cgetc() -> \"%c\"", key);

        switch(key) {
        case 'C':
            //clrscr();
            //drawMenuBar(0);
            cclearxy(0, SIZE_Y-1, SIZE_X);	
            gotoxy(0,SIZE_Y-1);
            printf("Enter Channel:");
            fgets(channel_name, sizeof channel_name, stdin);
            strncpy(channel_name, channel_name, strlen(channel_name));
            write_string_to_ram(RAM_DATA_START_ADDRESS, channel_name);
            write_byte(APPLE_COMMAND_ADDRESS, COMMAND_SET_CHANNEL);
            break;
        case ASCII_4:
            /*
            clrscr();
            drawMenuBar(0);
            read_string_from_ram(RAM_DATA_START_ADDRESS + address_offset, temperature, sizeof temperature-1);
            address_offset += strlen(temperature) + 1;
            read_string_from_ram(RAM_DATA_START_ADDRESS + address_offset, humidity, sizeof humidity-1);
            address_offset += strlen(humidity) + 1;
            read_string_from_ram(RAM_DATA_START_ADDRESS + address_offset, wind_speed, sizeof wind_speed-1);
            address_offset += strlen(wind_speed) + 1;
            read_string_from_ram(RAM_DATA_START_ADDRESS + address_offset, wind_direction, sizeof wind_direction-1);
            address_offset += strlen(wind_direction) + 1;
            read_string_from_ram(RAM_DATA_START_ADDRESS + address_offset, weather1, sizeof weather1-1);
            address_offset += strlen(weather1) + 1;
            read_string_from_ram(RAM_DATA_START_ADDRESS + address_offset, weather2, sizeof weather2-1);
            gotoxy(0,SIZE_Y-11);
            printf("%s (%s)\n", city, country_code);
            printf("-------------------------------------\n");
            printf("Temp:       %s K\n", temperature);
            printf("Humidity:   %s%%\n", humidity);
            printf("Wind Speed: %s m/s\n", wind_speed);
            printf("Wind Dir:   %s \n", wind_direction);
            printf("Summary:    %s, %s \n", weather1, weather2);
            printf("-------------------------------------\n");
            */
            break;
        default:
            break;
        }

    }
}
