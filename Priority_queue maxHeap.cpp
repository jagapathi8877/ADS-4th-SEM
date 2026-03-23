#include<bits/stdc++.h>
using namespace std;

class maxHeap
{
    vector<int>heap ;
    void heapifyUp(int idx)
    {
        while(idx > 0)
        {
            int i = (idx-1)/2 ;
            if(heap[idx] > heap[i])
            {
                swap(heap[idx] , heap[i]);
                idx = i ;
            }
            else break ;
        }
    }

    void heapifyDown(int idx)
    {
        while(idx < heap.size())
        {
            int lc = 2 * idx + 1 ;
            int rc = 2 * idx + 1 ;
            int large = idx ;
            if(lc < heap.size() && heap[lc] > heap[large]) large = lc ;
            if(rc < heap.size() && heap[rc] > heap[large]) large = rc ;
            if(large != idx)
            {
                swap(heap[large] , heap[idx]) ;
                idx = large ;
            }
            else break ;
        }
    }
public :
    void push(int val)
    {
        heap.push_back(val) ;
        heapifyUp(heap.size()-1) ;
    }
    void pop()
    {
        if(heap.size() == 0) return  ;
        heap[0] = heap.back() ;
        heap.pop_back();
        heapifyDown(0) ;
    }
    void display()
    {
        while(heap.size())
        {
            cout << heap[0] << " " ;
            pop() ;
        }
    }
};

int main()
{
    maxHeap heap;
    int n ;
    cin >> n ;
    vector<int>arr(n) ;
    for(int i = 0 ; i < n ; i++) cin >> arr[i] ;
    for(int i : arr) heap.push(i) ;
    heap.display() ;
}
