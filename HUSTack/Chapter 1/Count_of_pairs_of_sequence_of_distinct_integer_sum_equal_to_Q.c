#include <stdio.h>
#define MAX 1000000
int check(int used[],int num){
    return used[num]==1;
}
int a[MAX];
int used[MAX]={0};
int main(){
    int n,Q;
    scanf("%d",&n);
    scanf("%d",&Q);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        used[a[i]]++;
    }
    int count=0;
    for (int i=0;i<n;i++){
        int need=Q-a[i];
        if (need>=0&&need<MAX&&check(used,need)){
            if (a[i]!=need||used[a[i]]>1){
                count++;
                used[a[i]]=0;
                used[need]=0;
            }
        }
    }
    printf("%d",count);
    return 0;
}