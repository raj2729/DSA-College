#include<stdio.h>
#include<stdlib.h>
struct bstnode
{
	int data;
	struct node *left,*right;
};
struct bstnode *rootPtr=NULL;

struct bstnode *insert(int data)
{
	struct bstnode *temp=(struct bstnode*)malloc(sizeof(struct bstnode));
	temp->data=data;
	if(rootPtr==NULL)
	{
		rootPtr=temp;
		temp->left=NULL,temp->right=NULL;
	}
	else if(data<=root->data)
	{
		root->left=insert(data);
	}
	else if(data>=root->data)
	{
		root->right=insert(data);
	}
	
}
