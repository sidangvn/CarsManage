/*	I Pledge my Honor that I have not cheated, and will not cheat, on this assignment - Si Dang
 	THIS PROGRAM CONTAINS ALL FUNCTIONS AND 2 HEADER FILES WHICH ARE car.h AND readline.h
 	THE PROGRAM WAS MODIFIED THE APPEND FUNCTION SO IT SORTS THE CARS IN THE LIST IN ALPHABETICAL ORDER BY MAKE MODEL COLOR AND YEAR
	The program was written by Si Dang #U25273656 
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "car.h"
#include "readline.h"

#define LEN 30

//append function
struct car *append_to_list(struct car *list)
{
	struct car* Ncar = (struct car*)malloc(sizeof(struct car));/*allocate memory*/
	//struct car* current = list; /*structure tag called*/
	Ncar -> next = NULL; /*last linked list*/
	
	//prompt users input values
	printf("Enter make: ");
	read_line(Ncar -> make, LEN);
	printf("Enter model: ");
	read_line(Ncar -> model, LEN);
	printf("Enter color: ");
	read_line(Ncar -> color, LEN);
	printf("Enter year: ");
	scanf("%d", &Ncar -> year);
	printf("Enter city mpg: ");
	scanf("%d", &Ncar -> city_mpg);
	printf("Enter highway mpg: ");
	scanf("%d", &Ncar -> highway_mpg);
	printf("Enter quantity: ");
	scanf("%d", &Ncar -> quantity);

	//checking duplicate cars
	if(list == NULL)/*list not found*/
	{
		return Ncar;
	} 
	else /*list found*/
	{
		struct car* Car = list;
		while(Car != NULL)
		{	//New car details gonna be current car details, using string coppy
			if((strcmp(Car -> make, Ncar -> make) == 0) && (strcmp(Car -> model, Ncar -> model) == 0) &&
				(strcmp(Car -> color, Ncar -> color) == 0) && (Car -> year == Ncar -> year))
			{	
				printf("Car already exists!\n");
				return list;
			}
			
			//insert in order list
			if(Car -> next != NULL)
			{
  				Car = Car -> next;
  			}
			else
			{
				break;
			}
		}
		Car = list;
		//input car comes before the first car in the list
		if((strcmp(Ncar -> make, Car -> make) < 0) || ((strcmp(Ncar -> make, Car -> make) == 0) && (strcmp(Ncar -> model, Car -> model) < 0)) || ((strcmp(Ncar -> make, Car -> make) == 0) && (strcmp(Ncar -> model, Car -> model) == 0) 
			&& (strcmp(Ncar -> color, Car -> color) < 0)) || ((strcmp(Ncar -> make, Car -> make) == 0) && (strcmp(Ncar -> model, Car -> model) == 0) && (strcmp(Ncar -> color, Car -> color) == 0) && (Ncar -> year < Car -> year)))
		{
			Ncar -> next = list;
			list = Ncar;
			return list;
		}
		struct car* fcar = Car; /*fcar is previous car*/
        Car = list -> next;
		//find the best position for the new car then insert it into the list
		while(Car -> next != NULL)
		{
			//by make, model, color and year
			if((strcmp(Ncar -> make, Car -> make) < 0) || ((strcmp(Ncar -> make, Car -> make) == 0) && (strcmp(Ncar -> model, Car -> model) < 0)) 
			|| ((strcmp(Ncar -> make, Car -> make) == 0) && (strcmp(Ncar -> model, Car -> model) == 0) && (strcmp(Ncar -> color, Car -> color) < 0)) 
			|| ((strcmp(Ncar -> make, Car -> make) == 0) && (strcmp(Ncar -> model, Car -> model) == 0) && (strcmp(Ncar -> color, Car -> color) == 0) && (Ncar -> year < Car -> year)))
        	{
				Ncar -> next = Car;
				fcar -> next = Ncar;
				return list;
			}
			fcar = Car;
			Car = Car -> next;
		}
		Car -> next = Ncar;
		return list;
	}
	return NULL;
}

//delete car function
struct car* delete_from_list(struct car *list)
{
	//declaration
	char Dmake[LEN + 1];
	char Dmodel[LEN + 1]; 
	char Dcolor[LEN + 1];
	int year = 0;
	struct car* previous = NULL;
	struct car* current = NULL;
	
	//check available list
	if(list == NULL)
	{
		return NULL;
	}
	
	//propmt users enter
	printf("Enter make: ");
	read_line(Dmake, LEN);
	printf("Enter model: ");
	read_line(Dmodel, LEN);
	printf("Enter color: ");
	read_line(Dcolor, LEN);
	printf("Enter year: ");
	scanf("%d", &year);
  
	previous = current = list;
	
	//current is available
	while(current != NULL)
	{
		//these are not the same then break
		if(!strcmp(Dmodel, current -> model) && !strcmp(Dmake, current -> make) && !strcmp(Dcolor, current -> color) && (year == current -> year))
		{
			break;  
		}
		//else the same
		previous = current;
		current = current -> next;
	}
	
	if(current == NULL)
	{
		printf("Car does not exist!\n");
		return list;
	}
	//if the car is in the current list
	else if(current == list)
	{
		list = list -> next;
		current -> next = NULL;
		free(current);
		printf("Car: %s %s %s %d deleted\n", Dmake, Dmodel, Dcolor, year);
		return list;
	}
	else /*the car is in the previous list*/
	{
		previous -> next = current -> next;
		current -> next = NULL;
		free(current);
		printf("Car: %s %s %s %d deleted\n", Dmake, Dmodel, Dcolor, year);
		return list;
	}
}

//Find car function
void find_car(struct car * list)
{
	struct car* current = list;/*structure tag called*/
	
	char Fmake[LEN + 1];/*Find make*/
	char Fmodel[LEN + 1];/*Find model*/
	//prompt users enter
	printf("Enter make: ");
	read_line(Fmake, LEN);
	printf("Enter model: ");
	read_line(Fmodel, LEN);
  
	int flag = 0;
	while(current != NULL) /*current list existed*/
	{
		/*Users find car's input fits with element in the list*/
		if((strcmp(current -> make, Fmake) == 0) && (strcmp(current -> model, Fmodel) == 0)) 
		{
			struct car *Ncar = current; /*structure tag called*/
			printf("Color: %s, Year: %d, City mpg: %d, Highway mpg: %d, Quantity: %d\n", Ncar -> color, Ncar -> year, Ncar -> city_mpg, Ncar -> highway_mpg, Ncar -> quantity);
			flag = 1;
		}
		current = current -> next;/*current list will move to the next position after it's current place*/
	}
  
	if(!flag) /*users input out of values*/
	{
		printf("Car not found!.\n");
	}
	printf("\n");  
}

//print out function
void printList(struct car *list)
{
	struct car *Ncar = list;/*structure tag called*/
	
	printf("%15s %15s %15s %15s %15s %15s %15s\n", "Make", "Model", "Color", "Year", "City mpg", "Highway mpg", "Quantity");/*Makes a nice output*/
	while(Ncar != NULL)
	{
		printf("%15s %15s %15s %15d %15d %15d %15d\n" , Ncar -> make, Ncar -> model, Ncar -> color , Ncar -> year, Ncar -> city_mpg, Ncar -> highway_mpg, Ncar -> quantity);
		Ncar = Ncar -> next; /*add to the end of linked list*/
	} 
	printf("\n");
}

//Free lists function
void clearList(struct car *list)
{
	struct car *Ncar = list;/*structure tag called*/
	struct car *flag;/*structure tag called*/
	
	while(Ncar != NULL)/*list existed*/
	{
		flag = Ncar -> next; /*flag gonna place after New car list*/
		free(Ncar);/*free list*/
		Ncar = flag;/*Now, it free all*/
	}
}

