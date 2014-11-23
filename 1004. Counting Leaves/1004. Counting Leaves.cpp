/**************************************************************
1004. Counting Leaves (30)

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
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
Input

Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
Output

For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.

Sample Input
2 1
01 1 02
Sample Output
0 1
****************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_INT 0x7fffffff

vector<int> child[100];
int main(){
	int N,M;
	cin>>N>>M;
	while(M--){
		int id,n,c;
		cin>>id>>n;
		while(n--){
			cin>>c;
			child[id].push_back(c);
		}
	}
	vector<int> leaf_cnt(N,0);
	queue<int> qn,qd;
	//qn记录数量，qd记录层数
	qn.push(1);qd.push(0);
	int n,d;
	while(!qn.empty()){
		n=qn.front();
		d=qd.front();
		qn.pop();qd.pop();
		if(child[n].empty()) leaf_cnt[d]++;
		vector<int>::iterator it=child[n].begin();
		for(;it!=child[n].end();it++){
			qn.push(*it);qd.push(d+1);
		}
	}
	cout<<leaf_cnt[0];
	for(int i=1;i<=d;i++){
		cout<<' '<<leaf_cnt[i];
	}
	cout<<endl;
}
/**************************************************************
    author: ws
    Language: C++
****************************************************************/
