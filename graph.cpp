#include<bits/stdc++.h>
using namespace std;
#define MX 100


void printGraph(vector< pair< pair<int,int>, int > > adjacent_list)
{
    for(int i=0; i<adjacent_list.size(); i++)
    {
        cout <<adjacent_list[i].first.first<< " "<<adjacent_list[i].first.second<<" "<<adjacent_list[i].second<<endl;
    }
}

int main()
{
    int vertices,edge;
    cout<<"Enter vertices and edge number : ";
    cin>>vertices>>edge;
    vector< pair< pair<int,int>, int > > adjacent_list; /// vertices1 of edge, vertices2 of edge, weight
    cout<<"Enter vertices of canected edge : ";
    int x,y,z;
    for(int i=0; i<edge; i++)
    {
        cin>>x>>y>>z;
        adjacent_list.push_back(make_pair( make_pair(x,y), z ));
    }
    cout<<endl;
    printGraph(adjacent_list);





    return 0;
}

/**

5 6

0 1 2
1 2 2
4 2 4
1 3 1
0 4 3
2 3 1



*/
