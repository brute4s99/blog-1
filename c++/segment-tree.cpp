#include<iostream>
#include<algorithm>
using namespace std;

void buildTree(int *arr,int *tree,int start,int end,int treeNode){
	if(start == end){
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start+end)/2;
	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,2*treeNode+1);
	tree[treeNode] = min()
}	

int main(){
	int arr[] = {1,2,3,4,5};
	int *tree = new int[19];
	int n=4;
	int start=0,end=n-1;
	buildTree(arr,tree,start,end,treeNode);
}