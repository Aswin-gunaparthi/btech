#include<stdio.h>
#include<stdlib.h>
#define max 10
#include<stdbool.h>
#define inf 9999

int no_ed,G[max][max],n,x,y,start,distance[max];
bool known[max];

void prims_mst(int start){
    for(int i=0;i<n;i++){
        known[i] = false;
        distance[i] = inf;
    }
    
    known[start] = true;
    distance[start] = 0;
    no_ed = 0;
    
    while(no_ed < n-1){
        int min = inf;
        for(int i=0;i<n;i++){
            if(known[i] == true){
                for (int j=0;j<n;j++){
                    if(G[i][j] != 0 && known[j] == false){
                        if(G[i][j] < min){
                            min = G[i][j];
                             x = i;
                             y = j;
                        }
                    }
                }
            }
        }
        
    printf("Edge selected: (%d, %d) with weight %d", x, y, G[x][y]);
      known[y] = true;
      distance[y] = G[x][y];
      no_ed++;
    }
}
