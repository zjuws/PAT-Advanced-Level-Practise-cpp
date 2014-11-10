/**************************************************************
1005. Spell It Right (20)

时间限制
400 ms
内存限制
32000 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).

Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five

****************************************************************/


#include "stdio.h"
#include "string.h"
char words[10][10]={
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};
int main(){
	// printf("%s\n",words[1]);
	//char类型数组不用清零，%s赋值会覆盖
	char N[110];
	//通过字符串读入
	while(scanf("%s",N)!=EOF){
		int n=strlen(N);
		int ans=0;
		for(int i=0;i<n;i++){
			ans+=N[i]-'0';
		}
		// printf("----------%d\n",ans );
		//重新读为字符串
		sprintf(N,"%d",ans);
		// printf("------%s\n",N );
		n=strlen(N);
		for(int i=0;i<n-1;i++){
			printf("%s ",words[N[i]-'0']);
		}
		printf("%s\n",words[N[n-1]-'0']);


	}
}



/**************************************************************
    author: ws
    Language: C
****************************************************************/