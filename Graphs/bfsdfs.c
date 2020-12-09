#include <stdio.h>
int MAX=10;
void breadth_first_search(int adj[][MAX],int visited[],int start)
{
	int queue[MAX],rear = -1,front = -1, i;
	queue[++rear] = start;
	visited[start] = 1;
	while(rear != front)
	{
		start = queue[++front];
		printf("%c   ",start + 65);
		for(i = 0; i < MAX; i++)
		{
			if(adj[start][i] == 1 && visited[i] == 0)
			{
				queue[++rear] = i;
				visited[i] = 1;
			}
		}
	}
}
void depth_first_search(int adj[][MAX],int visited[],int start)
{
	int stack[MAX];
	int top = -1, i;
	printf("%c   ",start + 65);
	visited[start] = 1;
	stack[++top] = start;
	while(top != -1)
	{
		start = stack[top];
		for(i = 0; i < MAX; i++)
		{
			if(adj[start][i] && visited[i] == 0)
			{
				printf("->");
				stack[++top] = i;
				printf("%c", i + 65);
				visited[i] = 1;
				break;
			}
		}
		if(i == MAX)
		top--;
	}
}
int main()
{
	int num;
	int visited[10] = {0};
	int adj[MAX][MAX], i, j, choice;
	printf("\n-----GRAPH TRAVERSAL ALGORITHMS-----");
	printf("\n1. BFS");
	printf("\n2. DFS");
	printf("\n3. EXIT");
	printf("\nEnter your choice : ");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
		printf("Enter the adjacency matrix:\n");
		printf("\nEnter number of vertices : ");
		scanf("%d",&num);
		for(i = 0; i < num; i++)
		{
			for(j = 0; j < num; j++)
			scanf("%d", &adj[i][j]);
		}
		printf("\nBFS Traversal : ");
		breadth_first_search(adj,visited,0);
		break;
		case 2:
		printf("Enter the adjacency matrix:\n");
		for(i = 0; i < MAX; i++)
		{
			for(j = 0; j < MAX; j++)
			scanf("%d", &adj[i][j]);
		}
		printf("\nDFS Traversal: ");
		depth_first_search(adj,visited,0);
		break;
		default:
		printf("\nEnter a valid input");
	}
}

