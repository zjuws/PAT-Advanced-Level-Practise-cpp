/**************************************************************
With the 2010 FIFA World Cup running, football fans the world over were becoming increasingly excited as the best players from the best teams doing battles for the World Cup trophy in South Africa. Similarly, football betting fans were putting their money where their mouths were, by laying all manner of World Cup bets.

Chinese Football Lottery provided a "Triple Winning" game. The rule of winning was simple: first select any three of the games. Then for each selected game, bet on one of the three possible results -- namely W for win, T for tie, and L for lose. There was an odd assigned to each result. The winner's odd would be the product of the three odds times 65%.

For example, 3 games' odds are given as the following:

 W    T    L
1.1  2.5  1.7
1.2  3.0  1.6
4.1  1.2  1.1
To obtain the maximum profit, one must buy W for the 3rd game, T for the 2nd game, and T for the 1st game. If each bet takes 2 yuans, then the maximum profit would be (4.1*3.0*2.5*65%-1)*2 = 37.98 yuans (accurate up to 2 decimal places).

Input

Each input file contains one test case. Each case contains the betting information of 3 games. Each game occupies a line with three distinct odds corresponding to W, T and L.

Output

For each test case, print in one line the best bet of each game, and the maximum profit accurate up to 2 decimal places. The characters and the number must be separated by one space.

Sample Input
1.1 2.5 1.7
1.2 3.0 1.6
4.1 1.2 1.1
Sample Output
T T W 37.98
****************************************************************/

#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
//定义结构体
struct odd{
	char s;
	double num;
	//构造函数
	odd(char s,double num):s(s),num(num){}
	//重载<号
	bool operator<(odd const &r) const{
		return num>r.num;
	}
};
int main(){
	double sum=1;
	//set不可重复，multiset元素可以重复；
	set<odd> myset;
	myset.clear();
	char fag[3];
	for(int i=0;i<3;i++){
		double w,t,l;
		cin>>w>>t>>l;
		myset.insert(odd('W',w));
		myset.insert(odd('T',t));
		myset.insert(odd('L',l));
		cout<<myset.begin()->s<<" ";
		sum*=myset.begin()->num;
		//记得每次set要清零
		myset.clear();

	}
	sum=(sum*0.65-1)*2;
	printf("%.2lf\n",sum);
	return 0;
}


/**************************************************************
   方法二
****************************************************************/
#include<map>
#include<string>
#include<iostream>
using namespace std;

void out(int f)
{
	if(f==0)
		cout<<"W ";
	else if(f==1)
		cout<<"T ";
	else
		cout<<"L ";
}

int main()
{
	
	double num[3][3];
	int i,j;
	//将数据先存到2维数组
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cin>>num[i][j];
	}
	int flag;
	double result=1;
	//寻找最大值
	for(i=0;i<3;i++)
	{
		double max=-1;
		flag=0;
		for(j=0;j<3;j++)
		{
			if(max<num[i][j])
			{
				flag=j;
				max=num[i][j];
			}
		}
		result=result*num[i][flag];
		//输出flag
		out(flag);
	}
	result=(result*0.65-1)*2;
	printf("%.2lf\n",result);
	return 0;
}

/**************************************************************
    author: ws
    Language: C++
****************************************************************/