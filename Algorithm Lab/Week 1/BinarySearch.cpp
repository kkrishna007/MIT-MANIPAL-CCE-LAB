//Kkrishna Saxena
//210953172  CCE - C
#include <iostream>
using namespace std;
int count;

int binarySearch(int arr[], int lo, int hi, int x)
{
    int m;
    count++;
    while (lo <= hi) {
        count++;
        m = (lo + hi) / 2;
        count++;
        count++;
        if (arr[m] == x){
            count++;
            return m;
        }
        count++;
        if (arr[m] < x){
            count++;
            lo = m + 1;
        }
        else{
            count++;
            count++;
            hi = m - 1;
        }
    }
    count++;
    return -1;
}

int main(void)
{
    int arr[25], n, x;
    count=0;
    cout<<"Enter no. of elements: ";
    cin>>n; cout<<"Enter "<< n <<" elements : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the element to be searched :";
    cin>> x;
    int result = binarySearch(arr,0,n,x);
    (result == -1)? cout<<"Element is not present in array" : cout<<"Element is present at index : " <<result;
    cout<<endl;
    cout<<"Number of steps for search function : "<<count;
    return 0;
}
