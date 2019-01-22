#include<iostream>
using namespace std;
int n;
void shortest(int **graph){
    int i,j,k,dist[n][n];
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=graph[i][j];
                }
            }


    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
                }
            }
        }

    for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                cout<<dist[i][j]<<" ";
                }
                cout<<endl;
            }
}
int main(){
    int e,x,y,i,j;
    cin>>n;
    cin>>e;
    int **graph=new int *[n];
    for(i=1;i<=n;i++){
        graph[i]=new int[n];
        for(j=1;j<=n;j++){
            cin>>graph[i][j];
        }
    }
    shortest(graph);
}
