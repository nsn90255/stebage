#include <stdio.h>
#include <string.h>
#include <cjson/cJSON.h>

void clearLines(int linesPrinted) {
    for(int i = 0; i < linesPrinted; i++) {    
	printf("\033[A");
	printf("\033[2K");
    }
}
char menu(char startInput) {
    // get menu file
    FILE *menufp = fopen("data/structure/menu.json", "r");
    if (menufp == NULL) {
	printf("Cannot access menu.json\n");
	return 1;
    }
    // write file into a string
    char menuContents[2048];
    int len = fread(menuContents, 1, sizeof(menuContents) -1, menufp);
    fclose(menufp);
    menuContents[len] = '\0';
    // parse values
    cJSON *menuJson = cJSON_Parse(menuContents);
    if (menuJson == NULL) {
	printf("Error parsing menu.json\n");
	return 1;
    }
    int count = cJSON_GetArraySize(menuJson);
    int linesPrinted = 0;
    for (int i = 0; i < count; ++i) {
        cJSON *item = cJSON_GetArrayItem(menuJson, i);
        cJSON *name = cJSON_GetObjectItem(item, "Name");
        cJSON *value = cJSON_GetObjectItem(item, "Value");
	// print menu items, get input for starting question
        if (cJSON_IsString(name) && cJSON_IsString(value) && strcmp(name->valuestring, "StartQuestion") == 0) {
            printf("%s", value->valuestring);
	    scanf("%c", &startInput);
	    linesPrinted++;
        } else if (cJSON_IsString(name) && cJSON_IsString(value)) {
            printf("%s\n", value->valuestring);
	    linesPrinted++;
        } 
    }
    // clear terminal and return the user input
    clearLines(linesPrinted);
    return startInput;
}
int main(int argc, char *argv[]) {
    // get menu
    char startInput = 'n';
    startInput = menu(startInput);
    fflush(stdin);
    if (startInput == 'Y' || startInput == 'y' || startInput == '\n') {
	printf("starting game\n");
    } else {
	printf("quitting game\n");
    }
    return 0;
}
