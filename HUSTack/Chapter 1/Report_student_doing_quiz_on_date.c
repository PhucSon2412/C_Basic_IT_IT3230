//Cần thống kê xem mỗi ngày có bao nhiêu lượt sinh viên làm trắc nghiệm.
//Input
//Thông tin về sinh viên làm trắc nghiệm ôn tập được cho theo các dòng định dạng như sau:
//<yyyy-mm-dd> <hh:mm:ss> <user_id> <question_id>: trong đó sinh viên có mã <user_id> làm câu hỏi <question_id> vào ngày giờ là <yyyy-mm-dd> <hh:mm:ss>
//Kết thúc dữ liệu là 1 dòng chứa dấu *
//Output
//Mỗi dòng ghi <yyyy-mm-dd> <cnt>: trong đó <cnt> là số lượt sinh viên làm trắc nghiệm trong ngày <yyyy-mm-dd>
//(chú ý: các dòng được sắp xếp theo thứ tự tăng dần của ngày thống kê, ngày thống kê nào mà không có lượt sinh viên làm trắc nghiệm thì không in ra)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
int date[3000][13][32]={0};
int main(){
    int i,j,k,n=0,y,m,d,h,mi,s;
    char user_id[10],question_id[10],str[100];;
    while(1){
        fgets(str,100,stdin);
        if(str[0]=='*') break;
        char *token = strtok(str, "-");
        sscanf(token, "%d", &y);
        token = strtok(NULL, "-");
        sscanf(token, "%d", &m);
        token = strtok(NULL, "-");
        sscanf(token, "%d", &d);
        date[y][m][d]++;
        n++;
    }
    for(i=0;i<3000;i++){
        for(j=0;j<13;j++){
            for(k=0;k<32;k++) if(date[i][j][k]!=0){
                printf("%i-",i);
                if(j<10) printf("0%i-",j);
                else if(j>=10) printf("%i-",j);
                if(k<10) printf("0%i ",k);
                else if(k>=10) printf("%i ",k);
                printf("%i\n",date[i][j][k]);
            }
        }
    }
}