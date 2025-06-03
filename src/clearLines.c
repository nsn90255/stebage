#include <stdio.h>
#include <string.h>
#include <cjson/cJSON.h>
void clearLines(int linesPrinted) {
    // in this order, go up a line and clear it
    for(int i = 0; i < linesPrinted; i++) {    
	printf("\033[A");
	printf("\033[2K");
    }
}
