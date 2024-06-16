#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> tree; // Segment tree array
    vector<int> arr;  // Original array
    int n;            // Size of the original array

    // Build the segment tree
    void build(int node, int start, int end) {
        if (start == end) {
            // Leaf node will have a single element
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            // Recursively build the left and right subtrees
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            // Internal node will have the sum of both of its children
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // Update the segment tree
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            // Leaf node
            arr[idx] = val;
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                // If idx is in the left child, recurse on the left child
                update(2 * node + 1, start, mid, idx, val);
            } else {
                // If idx is in the right child, recurse on the right child
                update(2 * node + 2, mid + 1, end, idx, val);
            }
            // Internal node will have the sum of both of its children
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // Query the segment tree for the sum in the range [L, R]
    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            // range represented by a node is completely outside the given range
            return 0;
        }
        if (L <= start && end <= R) {
            // range represented by a node is completely inside the given range
            return tree[node];
        }
        // range represented by a node is partially inside and partially outside the given range
        int mid = (start + end) / 2;
        int left_sum = query(2 * node + 1, start, mid, L, R);
        int right_sum = query(2 * node + 2, mid + 1, end, L, R);
        return left_sum + right_sum;
    }

public:
    // Constructor
    SegmentTree(vector<int>& input) {
        arr = input;
        n = arr.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    // Update a value at index idx to val
    void update(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }

    // Query the sum in the range [L, R]
    int query(int L, int R) {
        return query(0, 0, n - 1, L, R);
    }
};