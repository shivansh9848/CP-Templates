#include <iostream>
#include <vector>
using namespace std;

class SegmentTree
{
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    void build(int node, int start, int end)
    {
        if (start == end)
        {

            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;

            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);

            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void update(int node, int start, int end, int idx, int val)
    {
        if (start == end)
        {

            arr[idx] = val;
            tree[node] = val;
        }
        else
        {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid)
            {

                update(2 * node + 1, start, mid, idx, val);
            }
            else
            {

                update(2 * node + 2, mid + 1, end, idx, val);
            }

            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int query(int node, int start, int end, int L, int R)
    {
        if (R < start || end < L)
        {

            return 0;
        }
        if (L <= start && end <= R)
        {

            return tree[node];
        }

        int mid = (start + end) / 2;
        int left_sum = query(2 * node + 1, start, mid, L, R);
        int right_sum = query(2 * node + 2, mid + 1, end, L, R);
        return left_sum + right_sum;
    }

public:
    SegmentTree(vector<int> &input)
    {
        arr = input;
        n = arr.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    void update(int idx, int val)
    {
        update(0, 0, n - 1, idx, val);
    }

    int query(int L, int R)
    {
        return query(0, 0, n - 1, L, R);
    }
};