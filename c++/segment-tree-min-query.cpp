#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
void buildTree(int *arr,int *tree,int start,int end,int treeNode){
	if(start == end){
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start+end)/2;
	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,2*treeNode+1);
	tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]); 
}

 int query(int *tree,int start,int end,int queryStart,int queryEnd,int treeNode){
	// No overlap
	if(queryEnd < start || queryStart > end){
		return INT_MAX;
	} 
	// complete overlap
	if(queryStart <= start && queryEnd >= end){
		return tree[treeNode];
	}
	// Partial overlap
	int mid = (start + end)/2;
	int left = query(tree,start,mid,queryStart,queryEnd,2*treeNode);
	int right = query(tree,mid+1,end,queryStart,queryEnd,2*treeNode+1);
	return min(left,right);
}

int main(){
	int start,end,no_of_query,treeNode;
	int arr[] = {1,3,2,-2,4,5};
	int *tree = new int[23];
	buildTree(arr,tree,0,5,1);
	cin>>no_of_query;
	while(no_of_query--){
		int queryStart,queryEnd;
		cin>>queryStart>>queryEnd;
		cout<<"The minimum is:-"<<query(tree,0,8,queryStart,queryEnd,1);
	}
}