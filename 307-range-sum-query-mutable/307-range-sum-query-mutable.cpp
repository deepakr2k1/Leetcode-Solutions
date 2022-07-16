#define lc idx<<1
#define rc (idx<<1)|1

class SegmentTree {
public:
    struct Node {
        int val;
    };
    int n;
    vector<Node> t;
    Node empty;

    // Constructor
    SegmentTree(vector<int>& A) {
        n = A.size();
        t.resize(n << 2);
        build(1, 0, n - 1, A);
        empty.val = 0;
    }

    // combine
    Node combine(Node& l, Node& r) {
        Node ans;
        ans.val = l.val + r.val;
        return ans;
    }

    // build segment tree
    void build(int idx, int l, int r, vector<int>& A) {
        if(l > r) return;
        if(l == r) {                                // leaf node
            t[idx].val = A[l];
            return;
        }
        int mid = (l + r) / 2;
        build(lc, l, mid, A);
        build(rc, mid + 1, r, A);
        t[idx] = combine(t[lc], t[rc]);
    }

    // Query
    Node query(int idx, int start, int end, int ql, int qr) {

        if(ql > end || qr < start)                  // No overlap
            return empty;
        if(ql <= start && qr >= end)                // Complete query
            return t[idx];
        int mid = (start + end) / 2;                // Partial Overlap
        Node left_ans = query(lc, start, mid, ql, qr);
        Node right_ans = query(rc, mid + 1, end, ql, qr);
        return combine(left_ans, right_ans);
    }
    int query(int ql, int qr) {
        Node ans = query(1, 0, n - 1, ql, qr);
        return ans.val;
    }

    // Update
    void update(int idx, int start, int end, int i, Node newNode) {
        if(i<start || i>end) return;                // No overlap
        if(start == end) {                          // Leaf-node
            t[idx] = newNode;
            return;
        }
        int mid = (start + end) / 2;
        update(lc, start, mid, i, newNode);
        update(rc, mid + 1, end, i, newNode);
        t[idx] = combine(t[lc], t[rc]);
        return;
    }
    void update(int i, int val) {
        Node newNode;
        newNode.val = val;
        update(1, 0, n - 1, i, newNode);
    }

};
vector<int> A(30004);
SegmentTree tree(A);
class NumArray {   
public:
    NumArray(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            tree.update(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        tree.update(index, val);
    }
    
    int sumRange(int left, int right) {
        return tree.query(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */