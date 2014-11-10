/**************************************************************
1006. Sign In and Sign Out (25)

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
At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

Input Specification:

Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID number is a string with no more than 15 characters.

Output Specification:

For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133

****************************************************************/




#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
typedef struct student{
	//ID数组开大一点，原先开15有一个点不通过，测试了半天
	char ID[16];
	//记录字符串
	char stime[10];
	char endtime[10];
	//记录转换过后的值
	int istime;
	int iendtime;

}stu;
//比较开始时间
int cmp1(stu a,stu b){
	return a.istime<b.istime;
}
//比较结束时间
int cmp2(stu a,stu b){
	return a.iendtime>b.iendtime;
}
//字符串时间转int类型
int stringtoint(char * c){
	int HH,MM,SS,ans;
	sscanf(c,"%d:%d:%d",&HH,&MM,&SS);
	return ans=HH*60*60+MM*60+SS;
}
int main(){
	int M;
	while(scanf("%d",&M)!=EOF){
		if(M==0) continue;
		stu st[M];

		for(int i=0;i<M;i++){
			scanf("%s%s%s",st[i].ID,st[i].stime,st[i].endtime);
			st[i].istime=stringtoint(st[i].stime);
			st[i].iendtime=stringtoint(st[i].endtime);
		}
		//排序
		sort(st,st+M,cmp1);
		printf("%s ",st[0].ID);
		sort(st,st+M,cmp2);
		printf("%s\n",st[0].ID);

	}

}


/**************************************************************
   方法二
****************************************************************/


#include <iostream>
#include <string>
#include <set>
using namespace std;
#pragma warning(disable:4996)
#define MAX_INT 0x7fffffff
//结构体内只设置2个变量
struct Person {
	string id, time;
	//申明了构造函数
	Person(string id, string time) : id(id), time(time) {}
	//重载了比较符号
	bool operator<(Person const &r) const {
		return time < r.time;
	}
};

int main() {
	// freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N; cin >> N;
	//申明了set集
	set<Person> signin, signout;
	string id, in, out;
	while (N--) {
		cin >> id >> in >> out;
		signin.insert(Person(id, in));
		signout.insert(Person(id, out));
	}
	cout << signin.begin()->id << ' '
		<< signout.rbegin()->id << endl;
}

/**************************************************************
   方法三
****************************************************************/
//整体思路同方法一，比方法一简便
#include<map>
#include<string>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

struct Person
{
	//利用了c++的string
	string id;
	string in;
	string out;
};

vector<Person>p;

bool cmp1(Person a,Person b)
{
	//直接string比较，不用转换，比方法一简便
	return a.in<b.in;
}

bool cmp2(Person a,Person b)
{
	return a.out>b.out;
}

int main()
{
	//freopen("D://test.txt","r",stdin);
	int n;
	cin>>n;
	p.clear();
	for(int i=0;i<n;i++)
	{
		Person buf;
		cin>>buf.id>>buf.in>>buf.out;
		p.push_back(buf);
	}
	sort(p.begin(),p.end(),cmp1);
	cout<<p[0].id<<" ";
	sort(p.begin(),p.end(),cmp2);
	cout<<p[0].id<<endl;
	return 0;
}

/**************************************************************
    author: ws
    Language: C
****************************************************************/