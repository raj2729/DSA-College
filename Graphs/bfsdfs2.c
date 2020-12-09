#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int queue[MAX], vis[MAX], adj[MAX][MAX];
int rear=-1, front=-1, n;

void push(int val) {
     if (front==-1)
        front = rear = 0;
     else rear++;
        queue[rear] = val;
}

void pop(int val) {
     if (front==rear)
        front = rear = -1;
     else
        front++;
}

void takeInput() {
	int i,j;
     front = rear = -1; //clearing the queue
     printf("Enter number of vertices in graph: ");
     scanf("%d", &n);
     printf("Enter the adjacency matrix:\n");
     for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            scanf("%d", &adj[i][j]);
}

void bfs() {
	int i,v;
     for (i=1;i<=n;i++)
     vis[i] = -1; //-1 indicates unvisited, 1 visited
     push(1);
     vis[1] = 1;
     while (front!=-1) {
              v = queue[front];
             printf("%c -> ", (char)(64+v));
             pop(v);
             for ( i=1;i<=n;i++) {
             if (adj[v][i]==1 && vis[i]==-1) {
                 push(i);
                 vis[i] = 1;
             }
         }
     }
}

void dfs(int v) {
	int i;
     vis[v] = 1;
     printf("%c -> ",(char)(64+v));
     for (i=1;i<=n;i++) {
         if (adj[v][i]==1 && vis[i]==-1)
            dfs(i);
     }
}

int main() {
	int i;
//     printf("\n
     printf("\n1 to input graph");
     printf("\n2 to perform bfs");
     printf("\n3 to perform dfs");
     printf("\n4 to exit\n");
     int option;
     do {
         printf("Enter option: ");
         scanf("%d", &option);
         switch (option) {
         case 1: takeInput(); break;
         case 2: printf("BFS of graph is: ");
                 bfs();
                 printf("\n");
                 break;
         case 3: printf("DFS of graph is: ");
                 for (i=1;i<=n;i++)
                    vis[i] = -1;
                 dfs(1);
         printf("\n");
         break;
     }
     } while (option!=4);
     return 0;
}

