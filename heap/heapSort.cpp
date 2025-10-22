#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

void heapify(vector<int> &heap, int ind, int n)
{
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;
    int maxInd = ind;
    if (left < n && heap[left] > heap[ind])
    {
        maxInd = left;
    }
    if (right < n && heap[right] > heap[maxInd])
    {
        maxInd = right;
    }
    if (maxInd != ind)
    {
        swap(heap[maxInd], heap[ind]);
    }
}

vector<int> heapSort(vector<int> heap)
{
    int n = heap.size();
    vector<int> ans;
    // builidng the heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(heap, i, n);
    }
    // extracting the max
    int currSize = n;
    for (int i = n - 1; i >= 0; i--)
    {
        int maximum = heap[0];
        heap[0] = heap[i];
        ans.push_back(maximum);
        currSize--;
        heapify(heap, 0, currSize);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> arr = {2, 3, 19, 3, 5, 15, 10, 9};
    vector<int> ans = heapSort(arr);
    for (int n : ans)
    {
        printf("%d,", n);
    }
    return 0;
}
