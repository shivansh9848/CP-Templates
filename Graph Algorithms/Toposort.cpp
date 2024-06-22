#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#include <bits/stdc++.h>
#include <bits/stdc++.h>
void solve(int idx, stack<int> &st, vector<vector<int>> &adj, vector<int> &vis)
{
    if (vis[idx])
        return;
    vis[idx] = 1;
    for (auto it : adj[idx])
    {
        solve(it, st, adj, vis);
    }
    st.push(idx);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int n, int m)
{
    vector<vector<int>> adj(n);
    for (auto it : edges)
    {
        adj[it[0]].pb(it[1]);
    }
    stack<int> st;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        solve(i, st, adj, vis);
    }
    vector<int> ans;
    while (st.size())
    {
        ans.pb(st.top());
        st.pop();
    }
    return ans;
}