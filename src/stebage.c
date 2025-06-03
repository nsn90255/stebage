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
#include <cjson/cJSON.h>
#include "menu.h"
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
