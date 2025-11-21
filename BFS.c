#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 10

int G[max][max],n,start,visit[max];

int queue[max];
int rear = -1,front = -1;
void enqueue(int value){
    if(front = -1)
        front = 0;
    rear++;
    queue[rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void bfs(int start){
    if(n == 0)
        printf("graph is emptty");
    enqueue(start);
    visit[start] = 1;
    int u = start;
    while(queue[front] != -1){
        u = dequeue();
        printf("%d",u);
        
        for(int i=0;i<n;i++){
            if(G[u][i] ==1 && visit[i] == 0){
                enqueue(i);
                visit[i] = 1;
            }
        }
    }
}
