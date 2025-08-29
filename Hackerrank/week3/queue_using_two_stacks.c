#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int stack1[100000],stack2[100000];
int ind1= -1,ind2 = -1;

void push1(int x) {
    stack1[++ind1]=x;
}

void push2(int x)
{
    stack2[++ind2]=x;
}

int pop1()
{
return stack1[ind1--];
}

int pop2()
{
return stack2[ind2--];
}

int isEmpty1()
{
return ind1==-1;
}

int isEmpty2()
{
 return ind2==-1;
}

void enqueue(int x)
{
push1(x);
}

void transfer(){
    while(!isEmpty1())
    {
        push2(pop1());
    }
}

void dequeue(){
    if(isEmpty2()) {
        transfer();
    }
    if(!isEmpty2()) {
        pop2();
    }
}

void printFr()
{
    if(isEmpty2())
    {
    transfer();
    }
    if(!isEmpty2()) {
    printf("%d\n", stack2[ind2]);
    }}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int type;
        scanf("%d", &type);
        if(type == 1)
        {
            int x;
            scanf("%d", &x);
            enqueue(x);
        }
         else if(type==2)
          {
            dequeue();
        } 
        else if(type == 3)
         {
            printFr();
        }
    }
    
 
    return 0;
}

