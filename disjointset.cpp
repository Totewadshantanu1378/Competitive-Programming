#include <bits/stdc++.h>
using namespace std;
class disJoint
{
    vector<int> rank, size, parent;
    public:
    disJoint(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUpar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int upu = findUpar(u);
        int upv = findUpar(v);
        if (upu == upv)
            return;

        if (rank[upu] < rank[upv])
            parent[upu] = upv;

        else if (rank[upu] > rank[upv])
            parent[upv] = upu;

        else
        {
            parent[upu] = upv;
            rank[upv]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int upu = findUpar(u);
        int upv = findUpar(v);
        if (upu == upv)
            return;

        if (size[upu] < size[upv])
        {
            parent[upu] = upv;
            size[upv] += size[upu];
        }
        else
        {
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
};
int main() 
{ 
    disJoint obj(5); 
    obj.unionByRank(0, 2); 
    obj.unionBySize(4, 2); 
    obj.unionByRank(3, 1); 
    
    if (obj.findUpar(4) == obj.findUpar(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
    if (obj.findUpar(1) == obj.findUpar(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
  
    return 0; 
} 