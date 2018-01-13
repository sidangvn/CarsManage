/*	I Pledge my Honor that I have not cheated, and will not cheat, on this assignment - Si Dang
	THE PROGRAM CONTAINS THE MAIN FUNCTION AND IT DEPENDS ON 2 HEADER FILES WHICH ARE car.h AND readline.h
 	The program was wittern by Si Dang #U25273656 
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "car.h"
#include "readline.h"

#define LEN 30

int main(void)
{
	char code;
  
	struct car *car_list = NULL;
	printf("Operation Code: a for appending to the list, d for delete option in the menu, f for finding a car"
			", p for printing the list; q for quit.\n");
	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n') /* skips to end of line */
			;
		switch (code) {
			case 'a': car_list = append_to_list(car_list);
				break;
			case 'd': car_list = delete_from_list(car_list);
				break;
			case 'f': find_car(car_list);
				break;
			case 'p': printList(car_list);
				break;
			case 'q': clearList(car_list);
				return 0;
			default: printf("Illegal code\n");
		}
		printf("\n");
	}
}
