/**************************************************************
1003. Emergency (25)

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
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4
****************************************************************/

#include <stdio.h>
using namespace std;
//2维数组记录边的关系
int mat[502][502];
//记录最短距离
int Dis[502];
//记录是否并入集合
bool mark[502];
//记录最短路径条数
int pathcount[502];
//记录最大的队伍数
int maxteam[502];
//记录当前城市的队伍
int team[502];
#define INF 1<<30
int main(){
	int n,m,s,e;
	int a,b,l;
	while(scanf("%d %d %d %d",&n,&m,&s,&e)!=EOF){
		//对数据进行初始化
		for(int i=0;i<n;i++){
			Dis[i]=INF;
			mark[i]=false;
			pathcount[i]=0;
			maxteam[i]=0;
			for(int j=0;j<n;j++)
				mat[i][j]=mat[j][i] = INF;

		}
		for(int i=0;i<n;i++){
			scanf("%d",&team[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&l);
			mat[a][b]=mat[b][a]=l;
		}
		//dijstra算法
		Dis[s]=0;
		pathcount[s]=1;
		maxteam[s]=team[s];
		mark[s]=true;
		int newP=s;
		for(int i=1;i<n;i++){
			for(int j=0;j<n;j++){
				if(mark[j]==true) continue;
				if(Dis[j]>Dis[newP]+mat[newP][j]){
					Dis[j]=Dis[newP]+mat[newP][j];
					pathcount[j]=pathcount[newP];
					maxteam[j] = maxteam[newP]+team[j];
				}else if(Dis[j]==Dis[newP]+mat[newP][j]){
					pathcount[j]+=pathcount[newP];
					if(maxteam[newP]+team[j]>maxteam[j])
						maxteam[j] = maxteam[newP]+team[j];
				}
			}
			int min=INF;
			for(int j=0;j<n;j++){
				if(mark[j]==true) continue;
				if(Dis[j]==-1) continue;
				if(Dis[j]<min){
					min=Dis[j];
					newP=j;
				}
			}
			mark[newP]=true;

		}
		printf("%d %d\n",pathcount[e],maxteam[e]);
	}
	return 0;
}
/**************************************************************
    dijstra算法总结
****************************************************************/
#include "stdio.h"
int mat[502][502];
int Dis[502];
bool mark[502];
int INF=1<<30;
int n,m,s,e;
void dij(){
	//初始点
	Dis[s]=0;
	//对n个点进行遍历
	for(int i=0;i<n;i++){
		int p,min=INF;
		//找出权值最小的边加入集合里
		for(int i=0;i<n;i++) if(mark[i]==false&&Dis[i]<min) min=Dis[p=i];
		if(min==INF||p==e) return;
		mark[p]=true;
		//对其他点进行遍历
		for(int j=0;j<n;j++){
			if(mark[j]==false){
				int distcost=Dis[p]+mat[p][j];
				//printf("----------%d\n",distcost);
				if(Dis[j]>distcost){
					Dis[j]=distcost;
					//printf("----------%d\n",Dis[j]);
				}
			}

		}

	}
}
int main(){
	int a,b,l;
	while(scanf("%d %d %d %d",&n,&m,&s,&e)!=EOF){
		//初始化
		for(int i=0;i<n;i++){
			Dis[i] = INF;
			mark[i] = false;
			for(int j=0;j<n;j++)
				mat[i][j]=mat[j][i] = INF;
		}
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&l);
			mat[a][b] = mat[b][a] = l;
		}
		dij();
		printf("%d\n",Dis[e]);
	}
	return 0;

}

/**************************************************************
    author: ws
    Language: C++
****************************************************************/