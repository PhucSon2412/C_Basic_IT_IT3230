#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char c;
    struct node *next;
} Node;
Node *top=NULL;
Node* makeNode(char c){
    Node* newNode=(Node*) calloc(1,sizeof(Node));
    newNode->c=c;
    newNode->next=NULL;
    return newNode;
}
void push(char c){
    Node * newNode=makeNode(c);
    newNode->next=top;
    top=newNode;
}
char pop(){
    if(top==NULL){
        return 0;
    } else {
        char c=top->c;
        Node* tmp=top;
        top=top->next;
        free(tmp);
        return c;
    }
}
void destroy(){
    while(pop()!=0);
}
int check(char a,char b){
    if(a==40&&b==41) return 1;
    else if(a==91&&b==93) return 1;
    else if(a==123&&b==125) return 1;
    else return 0;
}
int main(){
    char c;
    while((c=getchar())!='\n'){
        if(top==NULL&&(c==41||c==93||c==125)){
            printf("0");
            return 0;
        } else if(c==40||c==91||c==123){
            push(c);
        } else if(c==41||c==93||c==125){
            char tmp=pop();
            if (!check(tmp,c)){
                printf("0");
                return 0;
            }
        }
    }
    if(top!=NULL){
        printf("0");
        return 0;
    }
    printf("1");
}