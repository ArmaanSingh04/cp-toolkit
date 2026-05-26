#include <bits/stdc++.h>

using namespace std;

// Disjoint set union data structure implementation
class DSU {
    vector<int> parent , size;

public:
    DSU(int nodes){
        parent.resize(nodes+1);
        size.resize(nodes+1 , 1);

        for(int i=0 ; i<=nodes ; i++) parent[i] = i;
    }

    int findUltimateParent(int node){
        if(parent[node] == node)
            return node;
        
        int x = findUltimateParent(parent[node]);
        parent[node] = x;  // path compression

        return x;
    }

    void unionBySize(int u , int v){
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int main(){
    DSU ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    cout << (ds.findUltimateParent(3) == ds.findUltimateParent(7)) << endl;
    ds.unionBySize(3 , 7);
    cout << (ds.findUltimateParent(3) == ds.findUltimateParent(7)) << endl;

    return 0;
}