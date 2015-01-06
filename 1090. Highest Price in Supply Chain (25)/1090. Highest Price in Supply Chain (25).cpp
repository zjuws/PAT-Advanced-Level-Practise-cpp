#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long LL;
const int inf=(1<<30);
const int N=110000;
const double eps=1e-8;
const LL mod = 1000000007;
//------------------------------
int Tree[N];
int num[N];
int f[N];
int findRoot(int x){
	if(Tree[x]==x) return x;
	int fx=Tree[x];
	Tree[x]=findRoot(Tree[x]);
	f[x]=f[fx]+f[x];
	return Tree[x];
}
void merge(int x,int y) {
    int fx = findRoot(x);
    int fy = findRoot(y);
    if(fx==fy) {

    }else {
        Tree[fx] = fy;
        f[fx] = (f[y] - f[x] + 1);
    }
}
int main(){
	int n,s;
	double p,r;
	while(~scanf("%d%lf%lf",&n,&p,&r)){
		for(int i=0;i<n;i++){
			Tree[i]=i;
			f[i]=0;
		}
		for(int i=0;i<n;i++){
			scanf("%d",&s);
			if(s==-1) continue;
			merge(i,s);
		}

		int sameN=0;
		int deep=0;
		for(int i=0;i<n;i++){
			findRoot(i);
			//printf("%d: %d\n",i,f[i]);
			if(f[i]>deep){
				deep=f[i];
				sameN=1;
			}else if(f[i]==deep){
				sameN++;

			}
		}
		double ansPrice=p;
		for(int i=0;i<deep;i++){
			ansPrice=ansPrice*(1+r/100);
		}
		printf("%.2lf %d",ansPrice,sameN);
	
	}
	return 0;
}