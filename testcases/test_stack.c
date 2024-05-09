#include<my_stack.h>
#include<stdio.h>
int main()
{
int succ;
int x1,x2,x3,x4,x5;
int *x;
x1=100;
x2=200;
x3=300;
x4=400;
x5=500;
Stack *stack;
stack=createStack(&succ);
if(stack==false)
{
printf("Unable to create stack\n");
return 0;
}
// push data on stack
pushOnStack(stack,(void *)&x1,&succ);
if(succ) printf("element pushed\n");
pushOnStack(stack,(void *)&x2,&succ);
if(succ) printf("element pushed\n");
pushOnStack(stack,(void *)&x3,&succ);
if(succ) printf("element pushed\n");
pushOnStack(stack,(void *)&x4,&succ);
if(succ) printf("element pushed\n");
pushOnStack(stack,(void *)&x5,&succ);
if(succ) printf("element pushed\n");

// size of stack
printf("Size of stack : %d\n",getSizeOfStack(stack));

//checking is stack empty
if(isStackEmpty(stack)) printf("Stack is empty\n");
else printf("Stack is not empty\n");

//checking top element of stack
x=(int *)elementAtTopOfStack(stack,&succ); 
printf("Element at top of stack is %d\n",*x);  

//poping data from stack
while(!isStackEmpty(stack))
{
x=(int *)popFromStack(stack,&succ);
printf("%d popped from stack\n",*x);
}

//destorying stack
destroyStack(stack);
return 0;
}