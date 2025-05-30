#include <stdio.h>
#include <cjson/cJSON.h>

int menu() {
    // get menu file
    FILE *fp = fopen("data/structure/menu.json", "r");
    if (fp == NULL) {
	printf("Cannot access menu.json\n");
	return 1;
    }
    // write file into a string
    char buffer[2048];
    int len = fread(buffer, 1, sizeof(buffer), fp);
    fclose(fp);
}
int main(int argc, char *argv[]) {
    // get menu
    menu();
    return 0;
}
