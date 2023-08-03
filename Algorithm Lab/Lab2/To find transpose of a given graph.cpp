//Kkrishna Saxena
//210953172  CCE - C
#include <iostream>
using namespace std;
int count;

int main(void)
{
    int A[10][10],T[10][10],n, m,x;
    count=0;
    cout<<"enter no. of vertices";
    cin>>n;
    cout<<"enter number of edges";
    cin>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    A[i][j]=0;
    int p,q;

    for(int i=1;i<=m;i++)
    {
        cout<<"enter Source";
        cin>> p;
        cout<<"enter destination ";
        cin>>q;
        A[p][q]=1;
    }

    cout<<"\nADJACENCY MATRIX \n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
                cout<<A[i][j];
        }
        cout<<"\n";
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            T[j][i]=A[i][j];
        }
    }

    cout<<"\nTRANSPOSE MATRIX \n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
                cout<<T[i][j];
        }
        cout<<"\n";
    }


}
