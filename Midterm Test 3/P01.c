#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct SUBMISSION
{
    char problemID[4];
    int hour;
    int minute;
    int second;
    char status[4];
    int point;
    struct SUBMISSION *pre;
    struct SUBMISSION *next;
} sm;

typedef struct USER
{
    char userID[11];
    sm *submit;
    struct USER *next;
} user;

user* head = NULL;

user* makeUser(char *id)
{
    user* newUser = (user *) calloc (1, sizeof(user));
    strcpy(newUser->userID, id);
    newUser->submit = NULL;
    newUser->next = NULL;
    return newUser;
}

sm* makeSubmission(char *id, char *time, char* status, int point)
{
    sm* newSubmit = (sm *) calloc (1, sizeof(sm));
    strcpy(newSubmit->problemID, id);
    sscanf(time, "%i%*c%i%*c%i", &newSubmit->hour, &newSubmit->minute, &newSubmit->second);
    strcpy(newSubmit->status, status);
    newSubmit->point = point;
    newSubmit->pre = NULL;
    newSubmit->next = NULL;
    return newSubmit;
}

void insertUser(char *id)
{
    user* u = makeUser(id);
    if ( head == NULL ) head = u;
    else
    {
        user *tmp = head;
        while (tmp->next != NULL) tmp = tmp->next;
        tmp->next = u;
    }
}

user* findUser(char *id)
{
    if ( head == NULL ) return NULL;
    else 
    {
        user *tmp = head;
        if ( strcmp(tmp->userID , id) == 0 ) return tmp;
        while (tmp != NULL)
        {
            if ( strcmp(tmp->userID , id) == 0 ) return tmp;
            tmp = tmp->next;
        }
    }
    return NULL;
}

void insertSubmit(user *u, char *s_id, char* time, char* status, int point)
{
    if ( u == NULL ) return;
    else 
    {
        sm* newSubmit = makeSubmission(s_id, time, status, point);
        if ( u->submit == NULL ) u->submit = newSubmit;
        else
        {
            sm *tmp = u->submit;
            while ( tmp->next != NULL )
            {
                if ( strcmp(tmp->problemID, s_id) == 0 )
                {
                    tmp->next->pre = newSubmit;
                    newSubmit->next = tmp->next;
                    newSubmit->pre = tmp;
                    tmp->next = newSubmit;
                    return;
                }
                tmp = tmp->next;
            }
            newSubmit->pre = tmp;
            tmp->next = newSubmit;
        }
    }
}

int timeCompare(char* time1, char* time2)
{
    int hour1, hour2, minute1, minute2, second1, second2;
    sscanf(time1, "%i%*c%i%*c%i", &hour1, &minute1, &second1);
    sscanf(time2, "%i%*c%i%*c%i", &hour2, &minute2, &second2);
    if ( hour1 > hour2 ) return 1;
    else if ( hour1 < hour2 ) return -1;
    else 
    {
        if( minute1 > minute2 ) return 1;
        else if ( minute1 < minute2 ) return -1;
        else
        {
            if ( second1 > second2 ) return 1;
            else if ( second1 < second2 ) return -1;
            else return 0;
        }
    }
}

int totalSubmit()
{
    if ( head == NULL ) return 0;
    else 
    {
        int count = 0;
        user *tmp_u = head;
        sm* tmp_s;
        while ( tmp_u != NULL )
        {
            tmp_s = tmp_u->submit;
            while ( tmp_s != NULL )
            {
                count++;
                tmp_s = tmp_s->next;
            }
            tmp_u = tmp_u->next;
        }
        return count;
    }
}

int totalERR()
{
    if ( head == NULL ) return 0;
    else 
    {
        int count = 0;
        user *tmp_u = head;
        sm* tmp_s;
        while ( tmp_u != NULL )
        {
            tmp_s = tmp_u->submit;
            while ( tmp_s != NULL )
            {
                if ( strcmp(tmp_s->status,"ERR") == 0) count++;
                tmp_s = tmp_s->next;
            }
            tmp_u = tmp_u->next;
        }
        return count;
    }
}

int totalERRofUser(char *id)
{
    if ( head == NULL ) return 0;
    else 
    {
        user *u = findUser(id);
        if ( u == NULL ) return 0;
        else 
        {
            int count = 0;
            sm* tmp_s = u->submit;
            while ( tmp_s != NULL )
            {
                if ( strcmp(tmp_s->status,"ERR") == 0) count++;
                tmp_s = tmp_s->next;
            }
            return count;
        }
    }
}

int totalPointofUser(char *id)
{
    if ( head == NULL ) return 0;
    else 
    {
        user *u = findUser(id);
        if ( u == NULL ) return 0;
        else 
        {
            int point = 0, max = 0;
            sm* tmp_s = u->submit;
            char tmpBuf[10] = { 0 };
            strcpy(tmpBuf, tmp_s->problemID);
            while ( tmp_s != NULL )
            {
                if ( strcmp(tmpBuf, tmp_s->problemID) == 0)
                {
                    if ( tmp_s->point > max ) max = tmp_s->point;
                }
                else 
                {
                    strcpy(tmpBuf, tmp_s->problemID);
                    point += max;
                    max = 0;
                    if ( tmp_s->point > max ) max = tmp_s->point;
                }
                tmp_s = tmp_s->next;
            }
            point += max;
            return point;
        }
    }
}

int submitTime(char *time1, char* time2)
{
    if ( head == NULL ) return 0;
    else 
    {
        int count = 0;
        user *tmp_u = head;
        sm* tmp_s;
        while ( tmp_u != NULL )
        {
            tmp_s = tmp_u->submit;
            while ( tmp_s != NULL )
            {
                char time3[9] = { 0 };
                sprintf(time3, "%i:%i:%i", tmp_s->hour, tmp_s->minute, tmp_s->second);
                if ( timeCompare(time3, time1) == 1 && timeCompare(time3, time2) == -1 ) count++; 
                tmp_s = tmp_s->next;
            }
            tmp_u = tmp_u->next;
        }
        return count;
    }
}

int main()
{
    char s[30] = { 0 }, u_id[11] = { 0 }, s_id[4] = { 0 }, time[9] = { 0 }, status[4] = { 0 };
    int point;
    while (1)
    {
        fflush(stdin);
        fgets(s, 29, stdin);
        if ( s[0] == '#' ) break;
        s[strlen(s) - 1] = '\0';
        sscanf(s, "%s %s %s %s %i", u_id, s_id, time, status, &point);
        user *u;
        if ( head == NULL )
        {
            head = makeUser(u_id);
            u = head;
        }
        else 
        {
            u = findUser(u_id);
            if (u == NULL)
            {
                user *tmp = head;
                while ( tmp->next != NULL )
                {
                    tmp = tmp->next;
                }
                tmp->next = makeUser(u_id);
                u = tmp->next;
            }
        }
        insertSubmit(u, s_id, time, status, point);
    }
    while (1)
    {
        scanf("%s", s);
        if ( s[0] == '#' ) break;
        else if ( strcmp(s,"?total_number_submissions") == 0 )
        {
            printf("%i\n", totalSubmit());
        }
        else if ( strcmp(s,"?number_error_submision") == 0 )
        {
            printf("%i\n", totalERR());
        }
        else if ( strcmp(s,"?number_error_submision_of_user") == 0 )
        {
            char id[11] = { 0 };
            scanf("%s", id);
            printf("%i\n", totalERRofUser(id));
        }
        else if ( strcmp(s,"?total_point_of_user") == 0 )
        {
            char id[11] = { 0 };
            scanf("%s", id);
            printf("%i\n", totalPointofUser(id));
        }
        else if ( strcmp(s,"?number_submission_period") == 0 )
        {
            char time1[9] = { 0 }, time2[9] = { 0 };
            scanf("%s %s", time1, time2);
            printf("%i\n", submitTime(time1, time2));
        }
    }
    
}