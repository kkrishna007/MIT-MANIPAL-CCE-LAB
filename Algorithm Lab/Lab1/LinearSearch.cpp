#include <iostream>
using namespace std;
int count;

int linearsearch(int arr[],int n, int x)
{
    int i;
    count++;
    for(int i=0;i<n;i++)
    {
        count++;
        count++;
        if (arr[i]==x)
        {
            count++;
            return i;
        }
    }
    count++;
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
    int result = linearsearch(arr, n, x);
    (result == -1)? cout<<"Element is not present in array" : cout<<"Element is present at index : " <<result;
    cout<<endl;
    cout<<"Number of steps for search function : "<<count;
    return 0;
}
