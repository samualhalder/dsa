#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
    vector<int> arr;
public:
    SegmentTree(int n){
        arr.resize(4*n);
    }
    void buildTree(int ind,int l,int r,vector<int> &nums){
        if(l>r){
            return ;
        }
        if(l==r){
            arr[ind]=nums[l];
            return;
        }
        int mid=(l+r)/2;
        buildTree(ind*2+1,l,mid,nums);
        buildTree(ind*2+2,mid+1,r,nums);
        arr[ind]=arr[ind*2+1]+arr[ind*2+2];
    }
    void updateTree(int ind,int l,int r,int i,int val){
        if(l==r){
            arr[ind]=val;
            return;
        }
        int mid=(l+r)/2;
        if(i<=mid){
            updateTree(ind*2+1,l,mid,i,val);
        }else{
            updateTree(ind*2+2,mid+1,r,i,val);
        }
        arr[ind]=arr[ind*2+1]+arr[ind*2+2];
    }
    int queryTree(int ind,int l,int r,int s,int e){
        if(l>e || r<s) return 0;
        if(l>=s && r<=e) return arr[ind];
        int mid=(l+r)/2;
        return queryTree(ind*2+1,l,mid,s,e) + queryTree(ind*2+2, mid+1, r, s, e);
    }
};


int main(){
    vector<int> nums={1,2,3,4,3,3,4,2,2,3,4,2,4,3,4,2,2,2};
    // vector<int> nums={1,2,3,4,4,3};
    int n=nums.size();
    SegmentTree* sg=new SegmentTree(n);
    sg->buildTree(0, 0, nums.size()-1, nums);
    cout<<sg->queryTree(0, 0, nums.size()-1, 1, 3);
}
