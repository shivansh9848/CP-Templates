
class SegmentTree
{
private:
    vector<int> tree;
    vector<int> lazy;
    vector<int> arr;
    int n;

    // Helper function to build the segment tree
    void build(int node, int start, int end)
    {
        if (start == end)
        {
            // Leaf node will have a single element
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            // Recursively build the left and right subtrees
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            // Internal node will have the sum of both of its children
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // Helper function to propagate lazy updates
    void propagate(int node, int start, int end)
    {
        if (lazy[node] != 0)
        {
            // Update the current node
            tree[node] += (end - start + 1) * lazy[node];

            // Propagate to children if it's not a leaf node
            if (start != end)
            {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            // Reset the lazy value of current node
            lazy[node] = 0;
        }
    }

    // Range update function
    void updateRange(int node, int start, int end, int L, int R, int val)
    {
        propagate(node, start, end);

        if (R < start || end < L)
        {
            // Out of range
            return;
        }

        if (L <= start && end <= R)
        {
            // Current segment is fully within range
            tree[node] += (end - start + 1) * val;

            // Propagate to children if it's not a leaf node
            if (start != end)
            {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }

            return;
        }

        // Partially in range
        int mid = (start + end) / 2;
        updateRange(2 * node + 1, start, mid, L, R, val);
        updateRange(2 * node + 2, mid + 1, end, L, R, val);

        // Update current node based on children
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // Range query function
    int queryRange(int node, int start, int end, int L, int R)
    {
        propagate(node, start, end);

        if (R < start || end < L)
        {
            // Out of range
            return 0;
        }

        if (L <= start && end <= R)
        {
            // Current segment is fully within range
            return tree[node];
        }

        // Partially in range
        int mid = (start + end) / 2;
        int leftSum = queryRange(2 * node + 1, start, mid, L, R);
        int rightSum = queryRange(2 * node + 2, mid + 1, end, L, R);

        return leftSum + rightSum;
    }

public:
    // Constructor
    SegmentTree(vector<int> &input)
    {
        arr = input;
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(0, 0, n - 1);
    }

    // Range update API
    void updateRange(int L, int R, int val)
    {
        updateRange(0, 0, n - 1, L, R, val);
    }

    // Range query API
    int queryRange(int L, int R)
    {
        return queryRange(0, 0, n - 1, L, R);
    }
};
