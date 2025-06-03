#include <stdio.h>
#include <string.h>
#include <cjson/cJSON.h>
#include "menu.h"
#include "clearLines.h"
char menu(char startInput) {
    // get menu file
    FILE *menufp = fopen("data/structure/menu.json", "r");
    // return if there's a problem opening the file
    if (menufp == NULL) {
	printf("Cannot access menu.json\n");
	return 1;
    }
    // write file into a string
    char menuContents[2048];
    // get size of parsed string
    int len = fread(menuContents, 1, sizeof(menuContents) -1, menufp);
    // close file
    fclose(menufp);
    // terminate string
    menuContents[len] = '\0';
    // parse values
    cJSON *menuJson = cJSON_Parse(menuContents);
    // return if the menu is a null pointer
    if (menuJson == NULL) {
	printf("Error parsing menu.json\n");
	return 1;
    }
    // get size of the array
    int count = cJSON_GetArraySize(menuJson);
    // keep track of printed lines for clearing later
    int linesPrinted = 0;
    // loop through every array item and print its value
    for (int i = 0; i < count; ++i) {
        cJSON *item = cJSON_GetArrayItem(menuJson, i);
        cJSON *name = cJSON_GetObjectItem(item, "Name");
        cJSON *value = cJSON_GetObjectItem(item, "Value");
	// print menu items, get input for starting question
        if (cJSON_IsString(name) && cJSON_IsString(value) && strcmp(name->valuestring, "StartQuestion") == 0) {
            printf("%s", value->valuestring);
	    // ask user whether to start or not
	    scanf("%c", &startInput);
	    linesPrinted++;
        } else if (cJSON_IsString(name) && cJSON_IsString(value)) {
            printf("%s\n", value->valuestring);
	    linesPrinted++;
        } 
    }
    // clear terminal and return the user input
    clearLines(linesPrinted);
    cJSON_Delete(menuJson);
    return startInput;
}
