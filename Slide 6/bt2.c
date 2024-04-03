#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 30

struct sinhvien
{
    int active;
    char name[10];
    char email[20];
};
typedef struct sinhvien sv;

sv list[MAX_SIZE];
int lenght = 0;

void insert(char *name, char *email)
{
    int i = 0;
    if(list[0].active == 1)
        while (list[i].active == 1)
            i++;
    list[i].active = 1;
    strcpy(list[i].name, name);
    strcpy(list[i].email, email);
    lenght++;
}

void merge(int L, int M, int R)
{
    sv ta[MAX_SIZE];
    int i = L, j = M + 1, k;
    for ( k = L; k <= R; k++)
    {
        if (i > M)
        {
            strcpy(ta[k].name,list[j].name);
            strcpy(ta[k].email,list[j].email);
            j++;
        }
        else if (j > R)
        {
            strcpy(ta[k].name,list[i].name);
            strcpy(ta[k].email,list[i].email);
            i++;
        }
        else if (strcmp(list[i].name,list[j].name) <= 0 )
        {
            strcpy(ta[k].name,list[i].name);
            strcpy(ta[k].email,list[i].email);
            i++;
        }
        else
        {
            strcpy(ta[k].name,list[j].name);
            strcpy(ta[k].email,list[j].email);
            j++;
        }
    }
    for ( k = L; k <= R; k++)
    {
        strcpy(list[k].name,ta[k].name);
        strcpy(list[k].email,ta[k].email);
    }
}

void msort(int L, int R)
{
    if (L >= R) return;
    int M = (L + R) / 2;
    msort(L, M);
    msort(M + 1, R);
    merge(L, M, R);
}

int find(int L, int R, char *name)
{
    if (L > R) return 0;
    if (L == R)
        if (strcmp(list[L].name,name) == 0) 
            return L;
    int M = (L + R) / 2;
    if (strcmp(list[M].name,name) == 0) return M;
    else if (strcmp(list[M].name,name) > 0) return find(L, M - 1, name);
    else return find(M + 1, R, name);
}

void Remove(char *name)
{
    int i = find(0, lenght - 1, name);
    while (list[i+1].active != 0)
    {
        strcpy(list[i].name, list[i+1].name);
        strcpy(list[i].email, list[i+1].email);
        i++;
    }
    list[i].active = 0;
}

void Store(char *filename){
    FILE *f = fopen(filename,"w+t");
    int i = 0;
    while (list[i].active != 0)
    {
        fprintf(f,"%i %s %s\n", i+1, list[i].name, list[i].email);
        printf("%i %s %s\n", i+1, list[i].name, list[i].email);
        i++;
    }
}

int main()
{
    int choose, i;
    for ( i = 0; i < MAX_SIZE; i++) list[i].active = 0;
    while (1)
    {
        system("cls");
        printf("1.Load\n2.Find\n3.Insert\n4.Sort\n5.Remove\n6.Store\n7.Quit\nType your choose : ");
        scanf("%i", &choose);
        if (choose == 7) return 0;
        else if (choose == 1)
        {
            printf("Enter file name : ");
            char filename[20] = {0};
            scanf("%s", filename);
            FILE* f = fopen(filename, "rt");
            while (f == NULL)
            {
                printf("File Not Found ! Enter again : ");
                fflush(stdin);
                scanf("%s", filename);
                FILE* f = fopen(filename, "rt");
            } 
            char buffer[100] = {0}, name[10] = {0}, email[20] = {0};
            while (fgets(buffer, sizeof(buffer) - 1, f) != NULL)
            {
                if(buffer[strlen(buffer) - 1] == '\n')
                    buffer[strlen(buffer) - 1] = '\0';
                sscanf(buffer,"%s %s", name, email);
                insert(name, email);
            }
            fclose(f);
        }
        else if (choose == 2)
        {
            msort(0, lenght - 1);
            char name[10] = {0};
            printf("Enter name : ");
            scanf("%s", name);
            int i = find(0, lenght - 1, name);
            printf("%s %s\n", list[i].name, list[i].email);
            getchar();
            getchar();
        }
        else if (choose == 3)
        {
            char name[10] = {0}, email[20] = {0};
            printf("Enter name and email : ");
            scanf("%s %s", name, email);
            insert(name, email);
        }
        else if (choose == 4)
        {
            msort(0, lenght - 1);
        }
        else if (choose == 5)
        {
            char name[10] = {0};
            printf("Enter name : ");
            scanf("%s", name);
            Remove(name);
        }
        else if (choose == 6)
        {
            char filename[20] = {0};
            printf("Enter output filename : ");
            scanf("%s", filename);
            Store(filename);
            getchar();
            getchar();
        }
    }
    
}