#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& arr)
{
    for(int x : arr) cout << x << " ";
    cout << endl;
}

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1, j = high;

    while(i <= j)
    {
        while(i <= high && arr[i] <= pivot) i++;
        while(j > low && arr[j] > pivot) j--;

        if(i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "BEFORE SORTING : ";
    print(arr);

    quickSort(arr, 0, n - 1);

    cout << "AFTER SORTING : ";
    print(arr);

    return 0;
}
