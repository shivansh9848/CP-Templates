#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#include <bits/stdc++.h>
// Bellman's algorithm(to find MST)

// Only works for DAG.To make it work for undirected graph replace
//HIGHER complexity than Dijkstra
// Bellman->(N*M) Dijstra -> (Mlog(N))
// Undirected edge by two directed edge directed oppsite to each other.
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges)
{
    vector<tuple<int, int, int>> adj;
    for (auto it : edges)
    {
        int a = it[0];
        int b = it[1];
        int c = it[2];
        adj.pb({a, b, c});
    }

    vector<int> ans(n + 1, INT_MAX);

    ans[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto it : adj)
        {
            auto [a, b, c] = it;
            if ((ans[a] != INT_MAX) && (ans[a] + c) < ans[b])
            {
                ans[b] = ans[a] + c;
            }
        }
    }
    return ans;
}
