#include <stdio.h>
#include <cjson/cJSON.h>

int menu() {
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
    for (int i = 0; i < count; ++i) {
        cJSON *item = cJSON_GetArrayItem(menuJson, i);
        cJSON *name = cJSON_GetObjectItem(item, "Name");
        cJSON *value = cJSON_GetObjectItem(item, "Value");

        if (cJSON_IsString(name) && cJSON_IsString(value)) {
            printf("%s\n", value->valuestring);
        } 
    }
    return 0;
}
int main(int argc, char *argv[]) {
    // get menu
    menu();
    return 0;
}
