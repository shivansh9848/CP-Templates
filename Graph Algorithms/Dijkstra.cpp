#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
//STEPS
// 1)Make a distance vector initialized to infinity.Priority Queue is a pair<int,int>{dist,node}
// 2)Mark dist[source]=0 and push{0,source} to priority_queue;
// 3)While q.size() Take top element of pq out,pop it out and for its each neighbour 
// check if expected distance is less than required.
// if yes update the distance vector and push the {dist,element} in queue  
vector<int> dijkstra(vector<vector<int>> &vec, int n, int m, int source)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto it : vec)
    {
        adj[it[0]].pb({it[2], it[1]});
        adj[it[1]].pb({it[2], it[0]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> ans(n, INT_MAX);
    pq.push({0, source});
    ans[source] = 0;

    while (!pq.empty())
    {
        auto [a, b] = pq.top();
        pq.pop();

        for (auto it : adj[b])
        {
            auto [c, d] = it;
            if ((c + a) < ans[d])
            {
                ans[d] = c + a;
                pq.push({c + a, d});
            }
        }
    }
    return ans;
}
vector<int> dx = {1, -1, 0, 0, 1, 1, -1, -1};
vector<int> dy = {0, 0, 1, -1, 1, -1, 1, -1};

int minimumEffortPath(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
    pq.push({0, 0, 0});
    ans[0][0] = 0;

    while (!pq.empty())
    {
        auto [a, b, c] = pq.top();
        pq.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = b + dx[i];
            int y = c + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;
            int effort = max(a, abs(v[x][y] - v[b][c]));
            if (effort < ans[x][y])
            {
                ans[x][y] = effort;
                pq.push({effort, x, y});
            }
        }
    }
    return ans[n - 1][m - 1];
}