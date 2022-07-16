#define lc idx<<1
#define rc (idx<<1)|1
/*
segment tree - struct default values, combine
lazy - pushUpdate
*/
class SegmentTree {
public:
    struct Node {
        // TODO: default values
        int val = 0;
        bool isPending = false;
        int pendingUpdate = 0;
    };
    int n;
    vector<Node> t;
    Node empty;

    // Constructor
    SegmentTree(vector<int>& A) {
        n = A.size();
        t.resize(n << 2);
        build(1, 0, n - 1, A);
    }

    // TODO: combine
    void combine(Node& par, Node& left_c, Node& right_c) {
        par.val = left_c.val + right_c.val;
    }

    // TODO: push update
    void pushUpdate(int idx, int start, int end) {
        t[idx].val = min(t[idx].val, t[idx].pendingUpdate);
        t[idx].isPending = false;
        if(start == end) return;
        t[lc].pendingUpdate = min(t[lc].pendingUpdate, t[idx].pendingUpdate);
        t[rc].pendingUpdate = min(t[rc].pendingUpdate, t[idx].pendingUpdate);
        t[lc].isPending = true;
        t[rc].isPending = true;
    }

    // build segment tree
    void build(int idx, int start, int end, vector<int>& A) {
        if(end > end) return;
        if(start == end) {                                  // leaf node
            t[idx].val = A[start];
            return;
        }
        int mid = (start + end) / 2;
        build(lc, start, mid, A);
        build(rc, mid + 1, end, A);
        combine(t[idx], t[lc], t[rc]);
    }

    // Query
    Node query(int idx, int start, int end, int ql, int qr) {
        if(ql > end || qr < start) return empty;                // No overlap
        if(t[idx].isPending) pushUpdate(idx, start, end);       // pending update
        if(ql <= start && qr >= end) return t[idx];             // Complete query
        int mid = (start + end) / 2;
        Node left_ans = query(lc, start, mid, ql, qr);
        Node right_ans = query(rc, mid + 1, end, ql, qr);
        Node ans;
        combine(ans, left_ans, right_ans);
        return ans;
    }
    int query(int ql, int qr) {
        // TODO:
        Node ans = query(1, 0, n - 1, ql, qr);
        return ans.val;
    }

    // Update
    void update(int idx, int start, int end, int index, Node newNode) {
        if(index<start || index>end) return;                    // No overlap
        if(t[idx].isPending) pushUpdate(idx, start, end);       // pending update
        if(start == end) {                                      // Leaf-node
            t[idx] = newNode;
            return;
        }
        int mid = (start + end) / 2;
        update(lc, start, mid, index, newNode);
        update(rc, mid + 1, end, index, newNode);
        combine(t[idx], t[lc], t[rc]);
    }
    void update(int index, int val) {
        // TODO:
        Node newNode;
        newNode.val = val;
        update(1, 0, n - 1, index, newNode);
    }

    // Lazy update - range update
    void updateRange(int idx, int start, int end, int ql, int qr, int val) {
        if(start > end || start > qr || end < ql) return;       // No overlap
        if(t[idx].isPending) pushUpdate(idx, start, end);       // pending update
        if(start >= ql and end <= qr) {                         // complete update
            // TODO: pendingUpdate
            t[idx].pendingUpdate = val;
            t[idx].isPending = true;
            return;
        }
        int mid = (start + end) / 2;
        updateRange(lc, start, mid, ql, qr, val);               // Updating left child
        updateRange(rc, mid + 1, end, ql, qr, val);             // Updating right child
        combine(t[idx], t[lc], t[rc]);
    }
    void updateRange(int ql, int qr, int val) {
        updateRange(1, 0, n - 1, ql, qr, val);
    }

    void print() {
        for(int i = 0; i < 4 * n; i++) {
            cout << i << " " << t[i].val << endl;
            cout << i << " " << (t[i].isPending ? 1 : 0) << endl;
            cout << i << " " << t[i].pendingUpdate << endl;
        }
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