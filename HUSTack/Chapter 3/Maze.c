#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int Maze[1000][1000]={0};
typedef struct queueNode{
    int r;
    int c;
    int cs;
} queueNode;
queueNode queue[1000*1000];
int main(){
    int i,j,rs,cs,r,c,front=-1,rear=0;
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    scanf("%i %i %i %i",&r,&c,&rs,&cs);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%i",&Maze[i][j]);
        }
    }
    queueNode start={rs-1,cs-1,0};
    queue[rear]=start;
    Maze[rs-1][cs-1]=1;
    while(rear!=front){
        queueNode current=queue[++front];
        for(i=0;i<4;i++){
            int rc=current.r+dr[i];
            int cc=current.c+dc[i];
            if(rc>=0&&rc<r&&cc>=0&&cc<c){
                if(Maze[rc][cc]==0){
                    Maze[rc][cc]=1;
                    queueNode next={rc,cc,current.cs+1};
                    queue[++rear]=next;
                }
            } else if(rc<0||rc>=r||cc<0||cc>=c){
                printf("%i",current.cs+1);
                return 0;
            }
        }
    }
    printf("-1");
    return 0;
}