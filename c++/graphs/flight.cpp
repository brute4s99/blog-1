#include<iostream>
#include<assert.h>
#include<algorithm>
#include<list>
#include<queue>
using namespace std;
vector <int> l[10005];
bool *visited=new bool[10005];
int from[10005];
void bfs(int sv,int ev,int n){
    int i;
    for(i=1;i<=n;i++){
        visited[i]=false;
    }
    queue <int> q;
    vector <int>::iterator it;
    visited[sv]=true;
    q.push(sv);
    while(!q.empty()){
        int s=q.front();
        q.pop();
        for(it=l[s].begin();it!=l[s].end();it++){
            if(!visited[*it]){
                visited[*it]=true;
                from[*it]=s;
                if(*it==ev){
                    return ;
                }
                q.push(*it);
            }
        }
    }

}
int main(){
    int i,n,m,t,c,u,v,x,y,count=0;
    cin>>n>>m>>t>>c;
    assert(1<=n && n<=1e3);
    assert(n-1<=m && n<=(n*(n-1))/2);
    assert(1<=c && c<=1e3);
    assert(1<=t && t<=1e3);
    if(n==1){cout<<"1\n1";return 0;}
    for(i=1;i<=m;i++){
        cin>>u>>v;
        l[u].push_back(v);
        l[v].push_back(u);
    }
    cin>>x>>y;
    for(int i=1;i<=n;i++){
        sort(l[i].begin(),l[i].end());
    }
    bfs(x,y,n);
    vector <int> a;
    a.push_back(y);
    count++;
    int k=from[y];
    while(k!=x){
        a.push_back(k);
        k=from[k];
        count++;
    }
    a.push_back(x);
    count++;
    cout<<count<<endl;
    for(i=a.size()-1;i>=0;i--){
        cout<<a[i]<<" ";
    }
    return 0;
}
