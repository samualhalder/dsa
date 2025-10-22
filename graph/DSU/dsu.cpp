#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent,rank,size;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        // dont increse the rank if one has greater rank than the other because,
        // if we attach it to other one the rank is not getting incresed.
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }else if(rank[ulp_v]>rank[ulp_u]){
            parent[ulp_u]=ulp_v;
        }else{
            // as both have same rank attaching one will increse the ohter rank by one
            // can visualize by making  tree like graphs and connect to each other.
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return ;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};

int main(){

}
