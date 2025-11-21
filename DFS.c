#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 10

int G[max][max],n,start,visit[max];

int stack[max],top = -1;
void push(int v) {
    stack[++top] = v;
}

int pop() {
    return stack[top--];
}

void dfs(   int start){
    int u = start;
    push(u);
    while(stack[top] != -1){
        u = pop();
        if(visit[u] == 0){
            printf("%d",u);
            visit[u] = 1;
        }
        for(int i=0;i<n;i++){
            if(G[u][i] =1 && visit[i] ==0)
                push(i);
        }
    }
}
