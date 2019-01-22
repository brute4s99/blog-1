#include<iostream>
using namespace std;

void buildTree(int *arr,int *tree,int start,int end,int treeNode){
	if(start == end){
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start + end)/2;
	buildTree(arr,tree,start,mid,2*treeNode); //Left side of tree
	buildTree(arr,tree,mid+1,end,2*treeNode+1); //Right side of tree
	tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

int main(){
	int start,end;
	cin>>start>>end;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int *tree = new int[18];
	buildTree(arr,tree,start,end,1);

	for(int i=1;i<18;i++){
		cout<<tree[i]<<endl;
	}
}