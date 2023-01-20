#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[1000000];
void merge(ll x,ll z,ll w,ll y)
{
    ll i,j,k,n1,n2,n3;
    ll L[1000],M[1000],R[1000];

    n1=z-x+1;
    n2=w-z;
    n3=y-w;
    for(i=0; i<n1; i++)
    {
        L[i]=arr[x+i];
    }
    for(i=0; i<n2; i++)
    {
        M[i]=arr[z+i+1];
    }
    for(i=0; i<n3; i++)
    {
        R[i]=arr[w+1+i];
    }
    L[n1]=100000000;
    M[n2]=100000000;
    R[n3]=100000000;
    i=j=k=0;
    for(ll a=x; a<=y; a++)
    {
        if(L[i]<=M[j])
        {
            if(L[i]<=R[k])
            {

                arr[a]=L[i];
                i++;
            }
            else
            {
                arr[a]=R[k];
                k++;
            }
        }
        else
        {
            if(M[j]<=R[k])
            {
                arr[a]=M[j];
                j++;
            }
            else
            {
                arr[a]=R[k];
                k++;
            }
        }
    }

}

void divideNconquer(ll x,ll y)
{
    ll z,w;
    if(x<y)
    {
        z=x+((y-x)/3);
        w=x+1+2*(y-x)/3;
        divideNconquer(x,z);
        divideNconquer(z+1,w);
        divideNconquer(w+1,y);
        merge(x,z,w,y);
    }
}
int main()
{
    ll n,a,b,c,d,i,j,k,l;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    divideNconquer(0,n-1);

    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
