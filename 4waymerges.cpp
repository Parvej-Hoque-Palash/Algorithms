#include<bits/stdc++.h>
using namespace std;
int arr[1000000];

void merge(int arr[],int x,int z,int w,int v,int y)
{
    int i,j,k,l,n1,n2,n3,n4;
    int L[1000],M1[1000],M2[1000],R[1000];

    n1=z-x+1;
    n2=w-z;
    n3=v-w;
    n4=y-v;
    for(i=0; i<n1; i++)
    {
        L[i]=arr[x+i];
    }
    for(i=0; i<n2; i++)
    {
        M1[i]=arr[z+i+1];
    }
    for(i=0; i<n3; i++)
    {
        M2[i]=arr[w+i+1];
    }
    for(i=0; i<n4; i++)
    {
        R[i]=arr[v+i+1];
    }
    L[n1]=100000000;
    M1[n2]=100000000;
    M2[n3]=100000000;
    R[n4]=100000000;
    i=j=k=l=0;
    for(int a=x; a<=y; a++)
    {
        if(L[i]<=M1[j])
        {
            if(L[i]<=M2[k])
            {
                if(L[i]<=R[l])
                {
                   arr[a]=L[i];
                   i++;
                }
                else
                {
                arr[a]=R[l];
                l++;
                }
            }
            else
            {
                arr[a]=M2[k];
                k++;
            }
        }
        else if(M1[j]<= M2[k])
        {
            if(M1[j]<= M2[k])
            {
                if(M1[j]<=R[l])
                {
                    arr[a]=M1[j];
                    j++;
                }
                else
                {
                    arr[a]=R[l];
                    l++;
                }
            }
            else
            {
                arr[a]=M2[k];
                k++;
            }
        }
        else
        {
            if(M2[k]<= R[l])
            {
                arr[a]=M2[k];
                k++;
            }
            else
            {
                arr[a]=R[l];
                    l++;
            }
        }
    }

}

void divideNconquer(int arr[],int x,int y)
{
    int z,w,v;
    if(x<y)
    {
        z=x+((y-x)/4);
        w=x+1+2*(y-x)/4;
        v=x+1+3*(y-x)/4;
        cout<<"Partition 1: ";
        for(int i=x ; i<=z; i++)
        {
            cout<<arr[i]<<", ";
        }
        cout<<endl;
        cout<<"Partition 2: ";
        for(int i=z+1 ; i<=w; i++)
        {
            cout<<arr[i]<<", ";
        }
        cout<<endl;
        cout<<"Partition 3: ";
        for(int i=w+1 ; i<=v; i++)
        {
            cout<<arr[i]<<", ";
        }
        cout<<endl;
        cout<<"Partition 4: ";
        for(int i=v+1 ; i<=y; i++)
        {
            cout<<arr[i]<<", ";
        }
        cout<<endl;
        divideNconquer(arr,x,z);
        divideNconquer(arr,z+1,w);
        divideNconquer(arr,w+1,v);
        divideNconquer(arr,v+1,y);
        merge(arr,x,z,w,v,y);
        cout<<"After merge: ";
        for(int i=x ; i<=y; i++)
        {
            cout<<arr[i]<<", ";
        }
        cout<<endl;
    }
}

int main()
{
    int n,a,b,c,d,i,j,k,l;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    divideNconquer(arr,0,n-1);
cout<<"Sorted array: ";
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

