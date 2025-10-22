#include <bits/stdc++.h>
using namespace std;

class Heap
{
    vector<int> arr;
    int heapSize;

public:
    Heap(int heapSize)
    {
        this->heapSize = heapSize;
    }
    void push(int val)
    {
        if (arr.size() == heapSize)
        {
            return;
        }
        arr.push_back(val);
        int currInd = arr.size() - 1;
        int parInd = (currInd - 1) / 2;

        while (currInd != 0 && arr[currInd] > arr[parInd])
        {
            swap(arr[currInd], arr[parInd]);
            currInd = parInd;
            parInd = (currInd - 1) / 2;
        }
    }
    void pop()
    {
        if (arr.size() == 0)
        {
            cout << "invalid operation" << endl;
            return;
        }
        int maxelm = arr[0];
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        int currind = 0;
        int cnt = 0;
        while (currind < arr.size())
        {
            if (cnt++ == 5)
            {
                break;
            }
            int l = currind * 2 + 1;
            int r = currind * 2 + 2;
            int maxind = currind;
            if (l < arr.size() && arr[l] > arr[currind])
            {
                maxind = l;
            }
            if (r < arr.size() && arr[r] > arr[maxind])
            {
                maxind = r;
            }
            if (maxind == currind)
            {
                break;
            }
            else
            {
                swap(arr[maxind], arr[currind]);
                currind = maxind;
            }
        }
        cout << maxelm << endl;
    }
    void printHeap()
    {
        for (int n : arr)
        {
            cout << n << ",";
        }
    }
};

int main()
{
    Heap *hp = new Heap(10);
    hp->push(10);
    hp->push(4);
    hp->push(3);
    hp->push(7);
    hp->push(1);
    hp->push(12);
    hp->pop();
    hp->pop();
    hp->pop();
    hp->pop();
    hp->pop();
    hp->pop();
    hp->pop();
    hp->printHeap();
}
