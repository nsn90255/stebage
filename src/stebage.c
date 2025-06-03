#include <stdio.h>
#include <string.h>
#include <cjson/cJSON.h>
#include "menu.h"
void clearLines(int linesPrinted) {
    // in this order, go up a line and clear it
    for(int i = 0; i < linesPrinted; i++) {    
	printf("\033[A");
	printf("\033[2K");
    }
}

int main(int argc, char *argv[]) {
    // get menu
    char startInput = 'n';
    startInput = menu(startInput);
    // start game if the user so desires
    if (startInput == 'Y' || startInput == 'y' || startInput == '\n') {
	printf("starting game\n");
    } else {
	printf("quitting game\n");
    }
    return 0;
}
