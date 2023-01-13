#include<bits/stdc++.h>
using namespace std;
#define MX 100
vector<int> adjacent_list[MX];
int visited[MX]={0};
int dis[MX];



void BFS(int src)
{
    queue<int>q;
    visited[src] = 1;   /// Visited ki na check korbe
    dis[src] = 0;
    q.push(src);    /// src e thaka value ke queue te push korbe

    while(!q.empty())
    {
        int node = q.front();   /// First value ta node e rakhbo
        q.pop();    /// first value ta pop kore dibo

        for(int i=0; i<adjacent_list[node].size(); i++)
        {
            int next = adjacent_list[node][i];
            if(visited[next] == 0)
            {
                visited[next] = 1;
                dis[next] = dis[node] + 1;
                q.push(next);
            }
        }
    }
}


void printGraph(vector<int> adjacent_list[],int vertics)
{
    for(int i=0; i<vertics; i++)
    {
        cout << "Adjacency list of vertex " << i<< " : ";
        for(int j=0; j<adjacent_list[i].size(); j++)
        {
            cout <<adjacent_list[i][j]<< ", ";
        }
        cout<<endl;
        ///
    }
}

int main()
{
    int vertics,edge;
    cout<<"Enter vertics and edge number : ";
    cin>>vertics>>edge;
    cout<<"Enter vertics of canected edge : ";
    int x,y;
    for(int i=0; i<edge; i++)
    {
        cin>>x>>y;
        adjacent_list[x].push_back(y);
        adjacent_list[y].push_back(x);
    }

    printGraph(adjacent_list,vertics);
    cout<<endl;


    int n;
    cout<<"Enter vertices that you want distance from other : ";
    cin>>n;
    BFS(n);
    for(int i=0; i<vertics; i++)
    {
        cout<<"From vertices "<<n<<" distance of "<<i<<" is : "<<dis[i]<<endl;
    }

    return 0;
}

/**

9 13

0 1
0 8
1 2
4 2
1 7
4 7
0 5
4 8
2 3
3 6
8 3
7 6
6 5


*/
