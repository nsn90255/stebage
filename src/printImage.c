/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <string.h>
int printImage(const char *imageToPrint) {
    // dir with images
    const char *imageDir = "data/images/";
    char fullImagePath[256];

    snprintf(fullImagePath, sizeof(fullImagePath), "%s%s", imageDir, imageToPrint);
    FILE *fptr = fopen(fullImagePath, "r");  
    if (fptr == NULL) {  
	fprintf(stderr, "Error opening file for %s. : ", fullImagePath);
	perror("");
        return 1;  
    }
    char ch;
    int linesPrintedForImage = 0;
    while ((ch = fgetc(fptr)) != EOF) {
	if (ch == '\n') {
	    linesPrintedForImage++;
	}
        putchar(ch);
    }
    fclose(fptr);  
    return linesPrintedForImage;
}
