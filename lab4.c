#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union status //information that is age dependent
{
	char school[20];
	float salary;
	int retired;
};

struct person //general information for each person
{
	char name[20];
	int age;
	union status status;
};

void add(struct person *p, int *counter);
void delete(struct person *p, int *counter);
void display(struct person *p, int counter);

int main()
{
	int choice=0; //command choice
	struct person people[20]; //initializes the structure
	int counter; 

	while(1)
	{
		printf("Please choose an option\n (1) to Add\n (2) to Remove\n (3) to Display\n (4) to Quit\n");
		scanf("%d", &choice);
	
		switch (choice)
		{
		case 1:
			add(people, &counter);
			break;
		case 2:
			delete(people, &counter);
			break;
		case 3:
			display(people, counter);
			break;
		case 4: 
			return 0;
		}
	}
return 0;
}

void add(struct person *p, int *counter)
{
	char temp[20];

	printf("Please enter the name of the person.\n");
	scanf("%s", temp);
	strcpy(p[*counter].name, temp);
	
	printf("Please enter the age of the person.\n");
	scanf("%d", &p[*counter].age);
	int tempage=p[*counter].age;
	
	char escuela[20];
	if (tempage<=21)
	{
		printf("What school do you go to?\n");
		scanf("%s", escuela);
		strcpy(p[*counter].status.school, escuela);
	}
	else if (tempage>21 && tempage<65)
	{
		printf("How much Ca$h Money per year?\n");
		scanf("%f", &p[*counter].status.salary);
	}
	else if (tempage>=65)
	{
		printf("How many years have you been in retirement?\n");
		scanf("%d", &p[*counter].status.retired);	
	}
	
	(*counter)++;
return;
}

void delete(struct person *p, int *counter)
{
	char temp[20];
	
	printf("What name do you want to remove?\n");
	scanf("%s", temp);
	
	for(int i=0; i<*counter; i++)
	{
		int q=strcmp(p[i].name, temp);
		if (q==0)
		{
			strcpy(p[i].name, p[i+1].name);
			p[i].age=p[i+1].age;
			p[i].status=p[i+1].status;
		}
	}
	(*counter)--;
return;
}

void display(struct person *p, int counter)
{

	for(int i=0;i<counter;i++)
	{
		if (p[i].age<=21)
			printf("Name: %s Age: %d School:  %s\n", p[i].name, p[i].age, p[i].status.school);
		else if (p[i].age>21 && p[i].age<65)
			printf("Name: %s Age: %d Salary:  %f\n", p[i].name, p[i].age, p[i].status.salary);
		else if (p[i].age>=65)
			printf("Name: %s Age: %d Years since retirement: %d\n", p[i].name, p[i].age, p[i].status.retired);
	}
return;
}
	 
	
	
	
 
