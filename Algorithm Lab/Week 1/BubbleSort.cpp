//Kkrishna Saxena
//210953172  CCE - C
#include <iostream>
using namespace std;

int count = 0;

void bubbleSort(int arr[], int n){
     for (int i = 0; i < n-1; i++) {
        count++;

        for (int j = 0; j < n-i-1; j++) {
            count++;

            count++;
            if (arr[j] > arr[j+1]) {

                count++;
                int temp = arr[j];


                count++;
                arr[j] = arr[j + 1];

                count++;
                arr[j + 1] = temp;
            }
        }

    }

}

int main()
{
    int n;
    cout << "Enter Size of Array: ";
    cin >>  n;


    int arr[n];
    cout << "Enter elements: \n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Sorting the Array using Bubble Sort" << endl;
    bubbleSort(arr, n);
    cout << "Sorted Array: " << endl;

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout <<  endl;
    cout << "Step Count: " << count << endl;

}











