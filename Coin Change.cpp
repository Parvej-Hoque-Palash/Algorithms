#include<bits/stdc++.h>
using namespace std;
int cost[10000];
int prev[10000];
int dp(int M, int d, int c[])
{
    int i,j;
    //int prev[M+10];
    cost[0] =0;
    prev[0] =0;
    for(i=1; i<=M; i++)
    {
        cost[i] = 1e5;
        for(j=1; j<= d; j++)
        {
            if(i>= c[j-1] && cost[i-c[j-1]]+1 < cost[i])
            {
                cost[i] = cost[i-c[j-1]] +1;
                prev[i] = c[j-1];
            }
        }
    }
    return cost[M];
}
int main()
{
     int i,j,m,n,a,b;
     int M;
     cout<<"Enter money that is exchanged "<<endl;
     cin>>M;
     int c[]={ 1,10,25};//coin
     int d = sizeof(c)/sizeof(c[0]);
     cout<<dp(M,d,c)<<endl;
     cout<<"M"<<"    ";
     for(i=0; i<=M; i++)
     {
         cout<<i<<"  ";
     }
     cout<<endl;
     cout<<"Cost"<<" ";
     for(i=0; i<=M; i++)
     {
         cout<<cost[i]<<"  ";
     }
     cout<<endl;
     cout<<"prev"<<" ";
     for(i=0; i<=M; i++)
     {
         cout<<prev[i]<<"  ";
     }


}
