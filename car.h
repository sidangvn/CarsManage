/*	I Pledge my Honor that I have not cheated, and will not cheat, on this assignment - Si Dang
 	THE PROGRAM CONTAINS THE FUNCTION PROTOTYPES
 	The program was wittern by Si Dang #U25273656 
*/

#ifndef CAR_H /*pair of inndef and endif protect file*/
#define CAR_H
#define LEN 30
struct car{
	char make[LEN+1];
	char model[LEN+1];
	char color[LEN+1];
	int year;
	int city_mpg;
	int highway_mpg;
	int quantity;
	struct car *next;
};

struct car *append_to_list(struct car *list);
struct car *delete_from_list(struct car *list);
void find_car(struct car *list);
void printList(struct car *list);
void clearList(struct car *list);

#endif
