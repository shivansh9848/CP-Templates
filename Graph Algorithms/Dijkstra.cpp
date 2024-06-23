// priority_queue<int,vector<int>,func>pq;

//Dijkstra's algorithm

// Initialize multiset by {0,0}//weight,node
// Take out from top.
// add neighbours with lesser than current distance to ans.
vector<int> dijkstra(vector<vector<int>> &vec, int n, int m, int source)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto it : vec)
    {
        adj[it[0]].pb({it[2], it[1]});
        adj[it[1]].pb({it[2], it[0]});
    }
    multiset<pair<int, int>> s;
    vector<int> ans(n, INT_MAX);
    s.insert({0, source}); // weight,node
    ans[source] = 0;
    while (s.size())
    {
        auto [a, b] = *s.begin(); // weight,node
        s.erase(s.begin());

        for (auto it : adj[b])
        {
            auto [c, d] = it;
            if (((c + a) < ans[d]))
            {
                ans[d] = c + a;
                s.insert({c + a, d});
            }
        }
    }
    return ans;
}
