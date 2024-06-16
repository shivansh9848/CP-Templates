vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// Multi-source BFS function
void multiSourceBFS(vector<vector<int>> &v, queue<pair<int, int>> &sources)
{
    int n = v.size();
    int m = v[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // Enqueue all initial sources
    while (!sources.empty())
    {
        auto [x, y] = sources.front();
        sources.pop();
        visited[x][y] = true;
        // Process node (x, y) here if needed
        // Example: v[x][y] = 2;
    }

    // BFS from all sources simultaneously
    while (!sources.empty())
    {
        auto [x, y] = sources.front();
        sources.pop();

        // Explore neighbors in all 4 directions
        for (auto [dx, dy] : directions)
        {
            int nx = x + dx;
            int ny = y + dy;

            // Check if the neighbor is within bounds and not visited
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                sources.push({nx, ny});
                // Process node (nx, ny) here if needed
                // Example: v[nx][ny] = 2;
            }
        }
    }
}