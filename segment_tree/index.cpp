#include <bits/stdc++.h>

using namespace std;
class SegTree
{
    vector<int> seg;
    int arrSize;
    void build(int ind, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(ind * 2 + 1, low, mid, arr);
        build(ind * 2 + 2, mid + 1, high, arr);
        seg[ind] = min(seg[ind * 2 + 1], seg[ind * 2 + 2]);
    }
    // always query on the ind of the segment not the query range
    int internalQuery(int ind, int l, int r, int low, int high)
    {
        // no overlap
        if (low > r || high < l)
            return INT_MAX;
        // complete overlap
        if (low >= l && high <= r)
            return seg[ind];
        // partial overlap
        int mid = (low + high) / 2;
        int l_ans = internalQuery(ind * 2 + 1, l, r, low, mid);
        int r_ans = internalQuery(ind * 2 + 2, l, r, mid + 1, high);
        // cout << "min at :" << ind << "," << l_ans << ":" << r_ans << endl;
        return min(l_ans, r_ans);
    };
    void internalUpdate(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
            internalUpdate(ind * 2 + 1, low, mid, i, val);
        else
            internalUpdate(ind * 2 + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[ind * 2 + 1], seg[ind * 2 + 2]);
    }

public:
    SegTree(vector<int> arr)
    {
        int n = arr.size();
        arrSize = n;
        seg.resize(n * 4 + 1);
        build(0, 0, n - 1, arr);
    }
    void printSegTree()
    {
        for (int n : seg)
        {
            cout << n << ",";
        }
    }
    int query(int l, int r)
    {
        return internalQuery(0, l, r, 0, arrSize - 1);
    }
    void update(int ind, int val)
    {
        return internalUpdate(0, 0, arrSize - 1, ind, val);
    }
};

int main()
{
    vector<int> arr = {2, 1, 0, 4, 3, 7};
    SegTree a(arr);
    cout << a.query(3, 5);
    cout << a.query(1, 3);
    cout << a.query(5, 5);
    return 0;
}
