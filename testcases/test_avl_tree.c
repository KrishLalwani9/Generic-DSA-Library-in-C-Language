#include<my_avl_tree.h>
#include<stdio.h>
#include<stdlib.h>
int myComparator(void *left,void *right)
{
int *leftInt,*rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (*leftInt)-(*rightInt);
}

int main()
{
char more;
int *x;
int num,ch;
AVLTree *tree;
AVLTreeInOrderIterator inOrderIterator;
AVLTreePreOrderIterator preOrderIterator;
AVLTreePostOrderIterator postOrderIterator;

bool succ;
tree=createAVLTree(&succ,myComparator);
if(succ==false)
{
printf("Unable to create tree, low on memory\n");
return 0;
}
while(1)
{
printf("1. Insert \n");
printf("2. In order traversal\n");
printf("3. Pre order traversal\n");
printf("4. Post order Traversal\n");
printf("5. Remove \n");
printf("6. Search \n");
printf("7. Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
if(ch==1)
{
printf("Enter number to be insert in tree  : ");
scanf("%d",&num);
fflush(stdin);
x=(int *)malloc(sizeof(int));
*x=num;
insertIntoAVLTree(tree,x,&succ);
if(succ) printf("address of item that contain %d inserted in tree\n",*x);
else printf("Unable to insert in tree\n"); 
}
if(ch==2)
{
printf("In Order Iteration start \n");
inOrderIterator=getAVLTreeInOrderIterator(tree,&succ);
if(succ)
{
while(hasNextInOrderElementInAVLTree(&inOrderIterator))
{
x=(int *)getNextInOrderElementFromAVLTree(&inOrderIterator,&succ);
printf("%d\n",*x);
}
}
}
if(ch==3)
{
printf("Pre Order Iteration start \n");
preOrderIterator=getAVLTreePreOrderIterator(tree,&succ);
if(succ)
{
while(hasNextPreOrderElementInAVLTree(&preOrderIterator))
{
x=(int *)getNextPreOrderElementFromAVLTree(&preOrderIterator,&succ);
printf("%d\n",*x);
}
}
}
if(ch==4)
{
printf("Post Order Iteration start \n");
postOrderIterator=getAVLTreePostOrderIterator(tree,&succ);
if(succ)
{
while(hasNextPostOrderElementInAVLTree(&postOrderIterator))
{
x=(int *)getNextPostOrderElementFromAVLTree(&postOrderIterator,&succ);
printf("%d\n",*x);
}
}
}
if(ch==5)
{
printf("Enter number to remove : ");
scanf("%d",&num);
fflush(stdin);
x=removeFromAVLTree(tree,&num,&succ);
if(succ) printf("%d is removed\n",*x);
else printf("%d is not found\n",num);
}
if(ch==6)
{
printf("Enter number to search : ");
scanf("%d",&num);
fflush(stdin);
x=getFromAVLTree(tree,&num,&succ);
if(succ) printf("%d is found\n",*x);
else printf("%d is not found\n",num);
}
if(ch==7) break;
}//main loop ends
destroyAVLTree(tree); 
return 0;
}