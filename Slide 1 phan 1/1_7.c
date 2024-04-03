//Viết chương trình có khả năng sinh ra các câu tự động sử dụng kỹ
//thuật lựa chọn dựa trên số ngẫu nhiên. Chương trình dùng bốn mảng
//xâu ký tự để lưu trữ các mạo từ (article), danh từ (noun), động từ
//(verb), giới từ (preposition). Câu được tạo ra bằng cách lựa chọn
//ngẫu nhiên các phần tử trong các mảng trên và ghép lại theo thứ tự:
//mạo từ, danh từ, động từ, mạo từ và danh từ. Câu sinh ra cần bắt
//đầu với kỹ tự in hoa và kết thúc với dấu chấm. Chương trình cần sinh
//ra tối thiểu 10 câu.
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
typedef char* STRING;
STRING articles[] = {"the", "a", "some", "any"};
STRING verbs[] = {"drove", "jumped", "ran", "walked","skipped"};
STRING nouns[] = {"boy", "girl", "dog", "car"};
STRING pres[] = {"to", "from", "over", "under", "on"};
int main(){
    char tmp[100] = { 0 };
	srand(time(NULL));
    for (int i = 0;i < 10;i++)
	{
		int j = rand() % 4;
		strcpy(tmp, articles[j]);
		tmp[0] = tmp[0] - 'a' + 'A';
		printf("%s ", tmp);
		j = rand() % 4;
		printf("%s ", nouns[j]);
		j = rand() % 5;
		printf("%s ", verbs[j]);
		j = rand() % 5;
		printf("%s ", pres[j]);
		j = rand() % 4;
		printf("%s.\n", nouns[j]);
	}
}