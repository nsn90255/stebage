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
    int len = fread(menuContents, 1, sizeof(menuContents), menufp);
    fclose(menufp);
}
int main(int argc, char *argv[]) {
    // get menu
    menu();
    return 0;
}
