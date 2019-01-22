//Cycle Detection for directed graph
#include <iostream>
#include<vector>
using namespace std;
int n,e;
vector <int> l[10000];
void addEdges(int u, int v)
{
    l[u].push_back(v);
}
bool check(int sv, bool visited[], bool recStack[])
{
    if (visited[sv] == false)
    {
        visited[sv]=true;
        recStack[sv]=true;
        vector <int> :: iterator it;
        for(it=l[sv].begin();it!=l[sv].end();it++){
            if(!visited[*it]&& check(*it,visited,recStack)){
                return true;
            }
            else if(recStack[*it]){
                return true;
            }

        }
    }
    recStack[sv]=false;
    return false;
}
bool cycle()
{
    bool *visited = new bool[n];
    bool *recStack = new bool[n];
    for (int i = 1; i <= e; i++)
    {
        if (check(i, visited, recStack))
        {
            return true;
            break;
        }
    }
    return false;
}
int main()
{
    int i,x,y;
    cin >> n >> e;
    for (int i = 1; i <= e; i++)
    {
        cin >> x >> y;
        addEdges(x, y);
    }
    if (cycle())
    {
        cout << "Cycle detected";
    }
    else{

        cout << "No cycle detected";
        }
}
