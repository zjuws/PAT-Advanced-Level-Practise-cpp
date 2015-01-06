#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
double dfs(int node ,double parentPrice,double r,vector<vector<int> >&graph,vector<int> &nProduct){
	double myPrice;
	if(node==0)
		myPrice=parentPrice;
	else
		myPrice=(1.0+r/100.0)*parentPrice;
	if(graph[node].empty())
		return myPrice*nProduct[node];
	double ret=0.0;
	for(int i=0;i<graph[node].size();i++){
		ret+=dfs(graph[node][i],myPrice,r,graph,nProduct);
	}
	return ret;

}
int main(){
	int n=0;
	double p=0.0;
	double r=0.0;
	cin>>n>>p>>r;
	vector<vector<int> >graph(n);
	vector<int> nProduct(n,0);
	int ki;
	for(int i=0;i<n;i++){
		cin>>ki;
		if(ki==0){
			cin>>nProduct[i];
		}
		else{
			graph[i].resize(ki);
			for(int j=0;j<ki;j++){
				cin>>graph[i][j];

			}
		}
	}
	printf("%.1lf\n",dfs(0,p,r,graph,nProduct));
	return 0;

}