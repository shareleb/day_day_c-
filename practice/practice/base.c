//#include<stdio.h>
//#include<stdlib.h>
//
//#include<string.h>
//	//在当前字符串位置上进行替换。
//
//	void replaceSpace(char *str, int length) {
//		int count = 0;
//		for (int i = 0; i < length; i++) {
//			if (str[i] == ' ')
//				count++;
//		}
//		for (int i = length - 1; i >= 0; i--) {
//			if (str[i] != ' ') {
//				str[i + 2 * count] = str[i];
//			}
//			else {
//				count--;
//				str[i + 2 * count] = '%';
//				str[i + 2 * count + 1] = '2';
//				str[i + 2 * count + 2] = '0';
//			}
//		}
//	}
//
//
//int main()
//{
//	//struct st s;
//	//s.age = 10;
//	//struct st st = { 1200 };
//	//printf("%d\n", st);
//	/*struct  student  s = { "leb",5 };
//	struct st ss;
//	
//	printf("姓名：%s  年龄:%d\n", s.name, s.age);*/
//	char s[20] = "we are big";
//	replaceSpace(s, 10);
//	printf("%s", s);
//	system("pause");
//	return 0;
//}