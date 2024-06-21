#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
class DSU
{
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    void make_set(int v)
    {
        parent[v] = v;
        size[v] = 1;
    }
    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    DSU dsu(n + 1);
    multiset<tuple<int, int, int>> s;
    for (int i = 0; i < m; i++)
    {
        auto [a, b] = g[i];
        auto [c, d] = a;
        s.insert({b, c, d});
    }
    vector<pair<pair<int, int>, int>> ans;
    while (s.size())
    {
        auto [a, b, c] = *s.begin();
        s.erase(*s.begin());
        if (dsu.find_set(b) == dsu.find_set(c))
            continue;
        ans.pb({{b, c},a});
        dsu.union_sets(c, b);
        
    }

    return ans;
}
