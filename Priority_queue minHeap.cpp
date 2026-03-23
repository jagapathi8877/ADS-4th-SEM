#include<bits/stdc++.h>
using namespace std ;

class minHeap
{
    vector<int>heap ;
    void heapifyUp(int idx)
    {
        while(idx > 0)
        {
            int i = (idx -1)/2 ;
            if(heap[idx] < heap[i]) 
            {
                swap(heap[idx] ,heap[i]) ;
                idx = i ;
            }
            else break ;
        }
    }
    void heapifyDown(int idx)
    {
        while(idx < heap.size())
        {
            int lc = 2 * idx + 1; 
            int rc = 2 * idx + 2 ;
            int small = idx ;
            if(lc < heap.size() && heap[lc] < heap[small] ) small = lc ;
            if(rc < heap.size() && heap[rc] < heap[small]) small = rc ;
            if(small != idx)
            {
                swap(heap[idx] , heap[small]) ;
                idx = small ;
            }
            else break ;
        }
    }
public : 
    void push(int val)
    {
        heap.push_back(val) ;
        heapifyUp(heap.size() - 1) ;
    }
    void pop()
    {
        if(heap.size() == 0) return  ;
        heap[0] = heap.back() ;
        heap.pop_back() ;
        heapifyDown(0) ;
    }
    void display()
    {
        while(heap.size())
        {
            cout << heap[0] << endl ;
            pop() ;
        }
    }
};
int main()
{
    minHeap heap;
    int n ;
    cin >> n ;
    vector<int>arr(n) ;
    for(int i = 0 ; i < n ; i++) cin >> arr[i] ;
    for(int i : arr) heap.push(i) ;
    heap.display() ;
}
