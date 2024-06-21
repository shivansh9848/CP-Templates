#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back

// Prims algorithm(to find MST)

// Initialize multiset by {0,0,-1}//weight,node,parent
// Take out from top.If node visited already skip
// Else mark it visited and add current edge to the answer
// Put its neighbours if not visited.

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        auto [a, b] = g[i];
        auto [c, d] = a;
        adj[c].pb({d, b});
        adj[d].pb({c, b});
    }
    multiset<tuple<int, int, int>> s;
    vector<int> visited(n + 1, 0);
    vector<pair<pair<int, int>, int>> ans;
    s.insert({0, 1, -1}); // weight,node,parent
    while (s.size())
    {
        auto [a, b, c] = *s.begin();
        s.erase(s.begin());
        if (visited[b])
            continue;
        if (c != -1)
        {
            ans.pb({{b, c}, a});
        }
        visited[b] = 1;
        for (auto it : adj[b])
        {
            auto [d, e] = it;
            if (visited[d] == 0)
            {
                s.insert({e, d, b});
            }
        }
    }
    return ans;
}

int main()
{
    int n = 5;  // number of nodes
    int m = 14; // number of edges
    vector<pair<pair<int, int>, int>> g = {
        {{1, 2}, 2},
        {{1, 4}, 6},
        {{2, 1}, 2},
        {{2, 3}, 3},
        {{2, 4}, 8},
        {{2, 5}, 5},
        {{3, 2}, 3},
        {{3, 5}, 7},
        {{4, 1}, 6},
        {{4, 2}, 8},
        {{4, 5}, 9},
        {{5, 2}, 5},
        {{5, 3}, 7},
        {{5, 4}, 9}};

    vector<pair<pair<int, int>, int>>
        mst = calculatePrimsMST(n, m, g);

    cout << "Edges in the MST:" << endl;
    for (auto &edge : mst)
    {
        cout << edge.first.first << " - " << edge.first.second << " with weight " << edge.second << endl;
    }

    return 0;
}
