/**************************************************************
1020. Tree Traversals (25)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> myrint;
struct node{
	int data;
	node *left;
	node *right;
};
queue<node *> result;
node * creatTree(int a[],int b[],int n){
	if(n<=0) return NULL;
	node * root=(node*)malloc(sizeof(node));
	root->data=a[n-1];
	root->left=NULL;
	root->right=NULL;
	int i;
	for(i=0;i<n;i++)
		if(b[i]==a[n-1]) break;
	root->left=creatTree(a,b,i);
	//a+i间接实现了后序的逐渐左移动
	root->right=creatTree(a+i,b+i+1,n-i-1);
	return root;

}
//层次遍历
void levelPrint(node * root){
	if(root!=NULL) result.push(root);
	while(!result.empty()){
		node *temp=result.front();
		if(temp->left!=NULL) result.push(temp->left);
		if(temp->right!=NULL) result.push(temp->right);
		myrint.push_back(temp->data);
		result.pop();
	}
}
int main(){
	int a[32],b[32];
	int n,i,j;
	while(scanf("%d",&n)!=EOF){
		myrint.clear();
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		node * root=creatTree(a,b,n);
		levelPrint(root);
		for(i=0;i<myrint.size();i++)
			printf(i==myrint.size()-1?"%d\n":"%d ",myrint[i]);
	}
	return 0;
}
/**************************************************************
    以下附上先序和中序构建二叉树
****************************************************************/
node * creatTree(int a[],int b[],int n){
	if(n<=0) return NULL;
	node *root=(node*)malloc(sizeof(node));
	root->data=a[0];
	root->left=NULL;
	root->right=NULL;
	int i;
	for(i=0;i<n;i++)
		if(b[i]==a[0]) break;
	root->left=creatTree(a+1,b,i);
	root->right=creatTree(a+i+1,b+i+1,n-i-1);
	return root;
}
/**************************************************************
    author: ws
    Language: C++
****************************************************************/