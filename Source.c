/*-------------------------------------------
Name: Sara Mohamed Taha

Task 2
---------------------------------------------*/




#include <stdio.h>
#include <string.h>
#define MAXSIZE 5

typedef struct mystack
{
	char arr[MAXSIZE];
	int top;
}stack;

void createStack(stack* st)
{
	st->top = -1;
}

void push(stack* st, int data)
{
	if (st->top == MAXSIZE - 1)	            	//check if full (size - 1)
	{
		printf("Stack Overflow\n");
	}
	else								//if not
	{
		st->top++;						//increment top
		st->arr[st->top] = data;		// top = new data
	}
}

int pop(stack* st)
{
	if (st->top == -1)	            	//check if empty
	{
		printf("Error. Stack is Empty\n");
		return 0;
	}
	else								//if not
	{
		printf("Deleted: %c\n", st->arr[st->top]);
		st->top--;						//decrement top
		return 1;
	}
}

void printStack(stack* st)
{
	if (st->top == -1)
		return;

	printf("The Stack: ");
	for (int i = st->top; i >= 0; i--)		//LIFO
	{
		printf("%c ", st->arr[i]);
	}
	printf("\n");
}

int getTop(stack* st)
{
	return st->top;
}

int isfull(stack* st)
{
	if (st->top == MAXSIZE - 1)		//if full
		return 1;
	else
		return 0;
}

int isempty(stack* st)
{
	if (st->top == -1)		//if empty
		return 1;
	else
		return 0;
}

int checker(stack* st, int* data)					//BRACKET CHECKER
{
	int A = 0;
	int B = 0;
	int C = 0;
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (st->arr[i] == '{')
		{
			A++;
			for (int i = 0; i < MAXSIZE; i++) {
				if (st->arr[i] == '}')
				{
					A++;
					break;
				}
			}
		}
		else if (st->arr[i] == '(')
		{
			B++;
			for (int i = 0; i < MAXSIZE; i++) {
				if (st->arr[i] == ')')
				{
					B++;
					break;
				}
			}
		}
		else if (st->arr[i] == '[')
		{
			C++;
			for (int i = 0; i < MAXSIZE; i++) {
				if (st->arr[i] == ']')
				{
					C++;
					break;
				}
			}
		}
	}
	
	if (A == 2 || B == 2 || C == 2) {
		printf("Balanced!\n");
		return 1;
	}
	else {
		printf("Unbalanced\n");
		return -1;
	}
}


int main()
{
	stack st;
	createStack(&st);

	char arr1[] = { '{','x','+','y','}' };
	char arr2[] = { '(','x','+','y',')' };
	char arr3[] = { '[','x','+','y',']' };
	char arr4[] = { '{','x','+','y',')' };

	for (int i = 0; i < MAXSIZE ; i++)			//pushing and checker
	{
		push(&st,arr4[i]);
		printStack(&st);
	}
	
	//checker(&st, st.arr[MAXSIZE - 1]);

	if (checker(&st, st.arr[MAXSIZE - 1]) == 1) //popping if balanced
	{
		for (int i = 0; i < MAXSIZE; i++)			
		{
			pop(&st);
			printStack(&st);
		}
	}

	printf("The Top is: %d ", getTop(&st));
	printf("\n");

	if (isfull(&st) == 1)
		printf("\nstack is full\n");
	else
		printf("\nstack is not full\n");

	if (isempty(&st) == 1)
		printf("\nstack is empty\n");
	else
		printf("\nstack is not empty\n");
}