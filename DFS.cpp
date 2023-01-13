#include<bits/stdc++.h>
using namespace std;
#define MX 100
vector<int> adjacent_list[MX];
int visited[MX]= {0};


void DFS(int src)
{
    visited[src] = 1;
    for(int i=0; i<adjacent_list[src].size(); i++)
    {
        int next = adjacent_list[src][i];
        if(visited[next] == 0)
        {
            DFS(next);
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
    cout<<"Enter vertices for DFS : ";
    cin>>n;
    DFS(n);
    for(int i=0; i<vertics; i++)
    {
        if(visited[i] == 1)
            cout<<"vertices "<<i<<" is Visited"<<endl;
        else
            cout<<"vertices "<<i<<" is Not Visited"<<endl;
    }

    return 0;
}

/**

10 13

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
