#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& arr)
{
    for(int x : arr) cout << x << " ";
    cout << endl;
}

void merge(vector<int>& arr, int l, int m, int h)
{
    vector<int> res;
    int i = l, j = m + 1;

    while(i <= m && j <= h)
    {
        if(arr[i] <= arr[j]) res.push_back(arr[i++]);
        else res.push_back(arr[j++]);
    }

    while(i <= m) res.push_back(arr[i++]);
    while(j <= h) res.push_back(arr[j++]);
    int x = 0 ; 
    for(int i = l ; i <= h ; i++) arr[i] = res[x++] ;
}

void mergeSort(vector<int>& arr, int l, int h)
{
    if(l < h)
    {
        int m = (l+h) /2 ;
        mergeSort(arr , l , m);
        mergeSort(arr , m+1 , h) ;
        merge(arr , l , m , h);
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

    mergeSort(arr, 0, n - 1);

    cout << "AFTER SORTING : ";
    print(arr);

    return 0;
}
