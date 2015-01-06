#include <iostream>
#include <map>
#include <string>
#define INF 1<<30
using namespace std;
int mat[210][210];
int dist[210];
bool mark[210];
//记录开心值
int happiness[210];
//记录总的开心值
int sumhap[210];
//记录平均开心值
int avg[210];
int rout[210];
//记录有多少条最短路径
int difr[210];
//记录路径长度
int ct[210];
string cities[210];
map<string,int> m;
int num=-1;
int n;
int ston(string s){
	if(m.find(s)!=m.end()) return m[s];
	else{
		num++;
		m[s]=num;
		return num;

	}

}
void init(){
	for(int i=0;i<n;i++){
		dist[i]=INF;
		mark[i]=false;
		happiness[i]=0;
		sumhap[i]=0;
		difr[i]=0;
		avg[i]=0;
		rout[i]=0;
		ct[i]=0;
		for(int j=0;j<n;j++){
			mat[i][j]=INF;
		}
	}
}
void dijk(){
	
	for(int i=0;i<n;i++){
		int p;
		//选出最短加入路径
		int min=INF;
		for(int j=0;j<n;j++) if(mark[j]==false&&dist[j]<min) min=dist[p=j];
		if(min==INF) return;
		mark[p]=true;
		for(int j=0;j<n;j++){
			if(mark[j]==true) continue;
			if(dist[j]>dist[p]+mat[p][j]){
				dist[j]=dist[p]+mat[p][j];
				rout[j]=p;
				sumhap[j]=sumhap[p]+happiness[j];
				ct[j]=ct[p]+1;
				avg[j]=sumhap[j]/ct[j];
				difr[j]=difr[p];
			}
			else if(dist[j]==dist[p]+mat[p][j]){
				difr[j]+=difr[p];
				if(sumhap[j]<sumhap[p]+happiness[j]){
					rout[j]=p;
					sumhap[j]=sumhap[p]+happiness[j];
					ct[j]=ct[p]+1;
				    avg[j]=sumhap[j]/ct[j];
				}else if(sumhap[j]==sumhap[p]+happiness[j]){
					if(avg[j]<sumhap[j]/(ct[p]+1)){
						rout[j]=p;
						ct[j]=ct[p]+1;
						avg[j]=sumhap[j]/ct[j];

					}

				}
			}
		}
	}

}
void printfrout(int x){
	if(rout[x]!=0) printfrout(rout[x]);
	
	cout<<cities[rout[x]]<<"->";

}

int main(){
	int k;
	string scity;
	string city;
	int hp;
	string sa,sb;
	int ia,ib,cost;
	while(cin>>n>>k>>scity){
		init();
		num=ston(scity);
		cities[num]=scity;

		for(int i=0;i<n-1;i++){
			cin>>city>>hp;
			num=ston(city);
			happiness[num]=hp;
			cities[num]=city;
		}
		for(int i=0;i<k;i++){
			cin>>sa>>sb>>cost;
			ia=ston(sa);
			ib=ston(sb);
			mat[ia][ib]=mat[ib][ia]=cost;
		}
		
		
		dist[0]=0;
		difr[0]=1;
		dijk();
		ib=ston("ROM");
		cout<<difr[ib]<<" "<<dist[ib]<<" "<<sumhap[ib]<<" "<<avg[ib]<<endl;
		printfrout(ib);
		cout<<"ROM"<<endl;
	}
}