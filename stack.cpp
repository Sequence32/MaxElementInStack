#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXSIZE 10000000

struct stack
{
    int stackPos[MAXSIZE];
    int top;
};

typedef struct stack STACK;
STACK s;
int curMax = 0;

void push(void);
void popTop(void);
void display(void);

int main() 
{
    int n;
    int choice;
    s.top = -1;

    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    push();
                	break;
                case 2:
                    popTop();
                	break;
                case 3:
                    display();
                	break;
            }
    }   
    return 0;
}

void push()
{
    int num;
    scanf("%d",&num);
    if(num > curMax)
    {
        curMax = num;
    }
    s.top = s.top + 1;
    s.stackPos[s.top] = num; 
}

void popTop()
{
    if(s.stackPos[s.top] == curMax)
    {
        s.top = s.top -1; 
        int temp = curMax;
        curMax = 0 ;
        for(int i=s.top; i>=0; i--)
        {
             if(s.stackPos[i] > curMax)
                curMax = s.stackPos[i];
        }
    }
    else
        s.top = s.top -1; 
}

void display()
{
    printf("%d\n",curMax);    
}
