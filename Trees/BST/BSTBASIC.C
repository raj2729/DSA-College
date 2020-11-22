#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct bstnode
{
	int data;
	struct bstnode *left;
	struct bstnode *right;
};
struct bstnode *root=NULL;

struct bstnode *get_new_node(int data)
{
	struct bstnode *new_node=(struct bstnode*)malloc(sizeof(struct bstnode));
	new_node->left=NULL;
	new_node->right=NULL;
	new_node->data=data;
	return new_node;
}
struct bstnode* insert(struct bstnode* root,int data)
{
	if(root==0)
	{
		root=get_new_node(data);
	}
	else if(data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	return root;
}
void search(struct bstnode *root,int data)
{
	 if(root==0) printf("Invalid\n");
	 else if(root->data==data) printf("%d found\n",data);
	 else if(data<=root->data) return search(root->left,data);
	 else return search(root->right,data);
}
int main()
{
	int data;
//	clrscr();
	root=insert(root,1);
	root=insert(root,2);
	root=insert(root,3);
	root=insert(root,4);
	root=insert(root,5);

	printf("Enter the data to be searched : ");
	scanf("%d",&data);
	search(root,data);
	getch();
}
