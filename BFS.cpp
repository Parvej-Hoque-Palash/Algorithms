#include<bits/stdc++.h>
using namespace std;

vector <int>graph[10];
int dis[10];
queue <int> Q;

int BFS(int start)
{
     int infi =100;
     for(int i=0; i<10; i++)
            dis[i]=infi;
     dis[start]=0;

     Q.push(start);
     while(!Q.empty())
     {
         int u=Q.front();
         Q.pop();

         for(int i=0; i<graph[u].size(); i++)
         {
             int v=graph[u][i];

             if(dis[v]> dis[u]+1)
             {
                 dis[v]=dis[u]+1;
                 Q.push(v);
             }
         }
     }
}

int main()
{
    int node,edge;
    int a,b;
    cin>>node>>edge;
    for(int i=1; i<=edge; i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<=node; i++)
    {
        int m=graph[i].size();
        cout<<"Adjacency List of Node "<<i<<": ";
        for(int j=0;j<m; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    //Call BFS for a node(2)
    BFS(2);

    for(int i=1; i<=node; i++)
    {
        cout<<" Distance from 2 to "<<i<<" is "<<dis[i]<<endl;
    }
}
