struct Node
{
    int len = 0;
    int pref = 0;
    int suff = 0;
    int best = 0;
    char left = 0;
    char right = 0;
};
class segmentTree {
    string s;
    vector<Node> tree;
    int n;

    Node merge(Node a,Node b)
    {
        if(a.len==0)return b;
        if(b.len==0)return a;

        Node res;
        res.len = a.len + b.len;
        res.left = a.left;
        res.right = b.right;

        res.pref = a.pref;
        res.suff = b.suff;
        res.best = max(a.best,b.best);

        if(a.right == b.left)
        {
            res.best = max(res.best,a.suff + b.pref);
            if(a.pref==a.len)res.pref = a.len + b.pref;
            if(b.suff == b.len)res.suff = b.len + a.suff;
        }
        return res;
    }
    void build(int idx, int l, int r) {
        if (l == r) {
            tree[idx] = {1,1,1,1,s[l],s[r]};
            return;
        }

        int mid = (l + r) / 2;
        build(2 * idx + 1, l, mid);
        build(2 * idx + 2, mid + 1, r);

        tree[idx] = merge(tree[2*idx+1],tree[2*idx+2]);
    }

    void update(int idx, int l, int r, int tar, char ch) {
        if (l == r) {
            s[l] = ch;
            tree[idx] = {1,1,1,1,ch,ch};
            return;
        }

        int mid = (l + r) / 2;
        if (mid >= tar)
            update(2 * idx + 1, l, mid, tar, ch);
        else
            update(2 * idx + 2, mid + 1, r, tar, ch);

        tree[idx] = merge(tree[2*idx+1],tree[2*idx+2]);
    }

    int query() { return tree[0].best;}

public:
    segmentTree(string& v) {
        s = v;
        n = s.size();
        tree.resize(4*n);
        build(0, 0, n - 1);
    }

    int up(int pos, char ch) {
        update(0, 0, n - 1, pos, ch);
        return query();
    }
};
class Solution {
public:
    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        int n = s.size();
        int k = qc.size();

        segmentTree st(s);
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(st.up(qi[i], qc[i]));
        }
        return ans;
    }
};