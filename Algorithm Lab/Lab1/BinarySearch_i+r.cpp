#include <iostream>
using namespace std;
int icount =0,sr =0;
int IBinary(int a[],int k,int n)
{
	icount++;
	  int high = n-1, low = 0;

    icount++;
    while(low <= high)
    {
        icount++;
        int mid = (high+low)/2;

        icount++;
        if(a[mid] == k)
        {
            icount++;
            return mid;
        }

        icount++;
        if(a[mid] < k)
        {
            icount++;
            low = mid+1;
        }

        icount++;
        if(a[mid] > k)
        {
            icount++;
            high = mid - 1;
        }
    }
  icount++;
    return -1;
}

int RBinary(int a[], int k, int l, int h)
{
    sr++;
    if(h >= l)
    {
        sr++;
        int mid = (h+l)/2;

        sr++;
        if(a[mid] == k)
        {
            sr++;
            return mid;
        }

        sr++;
        if(a[mid] > k)
        {
            sr++;
            return RBinary(a, k, l, mid-1);
        }

        sr++;
        if(a[mid] < k)
        {
            sr++;
            return RBinary(a, k, mid+1, h);
        }
    }
    sr++;
    return -1;
}
int main()
{
    int n,k,arr[20];
    cout << "Enter size of Array: ";
    cin >>  n;

    cout << "Enter elements into the array: \n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter Element to be searched:";
    cin >> k;



    int ri = IBinary(arr, k, n);
    int rr = RBinary(arr, k, 0, n-1);

    cout << "Binary Search (Iterative): ";
    if(ri == -1)
    {
        cout << "Element Not Found" << endl;
    }
    else
    {
        cout << "Element Found at " << ri << endl;
    }
    cout << "Step Count (Iterative): " << icount << endl;

    cout << endl;
    cout << "Binary Search (Recursive): ";
    if(rr == -1)
    {
        cout << "Element Not Found" << endl;
    }
    else
    {
        cout << "Element Found at " << rr << endl;
    }
    cout << "Step Count (Recursive): " << sr << endl;

}
