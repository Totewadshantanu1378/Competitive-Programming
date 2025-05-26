#include <bits/stdc++.h>
using namespace std;

class binaryLifting
{
public:
    vector<int> depth;
    vector<vector<int>> parent;

    binaryLifting(int n, vector<vector<int>> &adj)
    {
        depth.resize(n + 1);
        parent.resize(n + 1, vector<int>(31, -1));
        //   1 is the root , 1- based indexing
        store_depth(1, 0, adj);
        store_parent(1, -1, adj);
        markAncestor();
    }

    void markAncestor()
    {
        for (int i = 1; i < 30; i++)
        { // ith parent
            for (int j = 0; j < parent.size(); j++)
            { // jth node
                int par = parent[j][i - 1];
                if (par == -1)
                    continue;
                parent[j][i] = parent[par][i - 1];
            }
        }
    }
    void store_depth(int node, int deep, vector<vector<int>> &adj)
    {
        depth[node] = deep;
        for (auto it : adj[node])
        {
            store_depth(it, deep + 1, adj);
        }
    }
    void store_parent(int node, int par, vector<vector<int>> &adj)
    {
        parent[node][0] = par; // immediate parent storing
        for (auto adjnode : adj[node])
        {
            store_parent(adjnode, node, adj);
        }
    }
    int lca(int u, int v)
    {
        if (depth[u] > depth[v])
            swap(u, v);
        int extra = depth[v] - depth[u];
        for (int i = 0; i < 30; i++)
        {
            if (extra & (1 << i))
            {
                v = parent[v][i]; // it will jump to the ancestors accordingly
                                  // untill the u and v comes on same depth
            }
        }

        if (u == v)
            return u;

        for (int i = 29; i >= 0; i--)
        {
            if (parent[u][i] != parent[v][i])
            {
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        return parent[u][0];
    }
};
int main()
{
    int n = 13;
    vector<vector<int>> adj(n + 1);
    adj[1] = {2, 3};
    adj[2] = {4, 5};
    adj[3] = {6, 7};
    adj[4] = {8};
    adj[5] = {9};
    adj[6] = {10, 11};
    adj[7] = {12, 13};

    binaryLifting obj(n, adj);
    cout << "LCA of 9 and 8: " << obj.lca(9, 8) << endl; // Output should be 3
}