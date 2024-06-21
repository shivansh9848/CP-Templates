#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#include <bits/stdc++.h>
// Prims algorithm(to find MST)

// Initialize multiset by {0,0}//weight,node,parent
// Take out from top.If node visited already skip
// Else mark it visited and add current edge to the answer
// Put its neighbours if not visited.
vector<int> dijkstra(vector<vector<int>> &vec, int n, int m, int source)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto it : vec)
    {
        adj[it[0]].pb({it[2], it[1]});
        adj[it[1]].pb({it[2], it[0]});
    }
    multiset<pair<int, int>> s;
    vector<int> visited(n, 0);
    vector<int> ans(n, INT_MAX);
    s.insert({0, source}); // weight,node
    ans[source] = 0;
    while (s.size())
    {
        auto [a, b] = *s.begin(); // weight,node
        s.erase(s.begin());
        if (visited[b])
            continue;
        visited[b] = 1;
        for (auto it : adj[b])
        {
            auto [c, d] = it;
            if (visited[d] == 0 && ((c + a) < ans[d]))
            {
                ans[d] = c + a;
                s.insert({c + a, d});
            }
        }
    }
    return ans;
}
