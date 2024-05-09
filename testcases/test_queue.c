#include<my_queue.h>
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
Queue *queue;
queue=createQueue(&succ);
if(queue==false)
{
printf("Unable to create queue\n");
return 0;
}

//adding to queue
addToQueue(queue,(void *)&x1,&succ);
if(succ) printf("element added\n"); 
addToQueue(queue,(void *)&x2,&succ);
if(succ) printf("element added\n");
addToQueue(queue,(void *)&x3,&succ);
if(succ) printf("element added\n");
addToQueue(queue,(void *)&x4,&succ);
if(succ) printf("element added\n");
addToQueue(queue,(void *)&x5,&succ);
if(succ) printf("element added\n");

printf("Size of queue : %d\n",getSizeOfQueue(queue));

//checking is queue empty
if(isQueueEmpty(queue)) printf("Queue is empty\n");
else printf("Queue is not empty\n");

//checking top element of queue  
x=(int *)elementAtTopOfQueue(queue,&succ); 
printf("Element at top of queue is %d\n",*x);
 
//removing from queue
while(!isQueueEmpty(queue)) 
{
x=(int *)removeFromQueue(queue,&succ);
printf("%d removed from queue\n",*x);
}
//destoring queue 
destroyQueue(queue);
return 0;
}