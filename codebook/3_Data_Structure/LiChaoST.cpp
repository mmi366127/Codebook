struct L {
  int m, k, id;
  L() : id(-1) {}
  L(int a, int b, int c) : m(a), k(b), id(c) {}
  int at(int x) { return m * x + k; }
};
class LiChao { // maintain max
private:
  int n; vector<L> nodes;
  void insert(int l, int r, int rt, L ln) {
    int m = (l + r) >> 1;
    if (nodes[rt].id == -1)
      return nodes[rt] = ln, void();
    bool atLeft = nodes[rt].at(l) < ln.at(l);
    if (nodes[rt].at(m) < ln.at(m))
      atLeft ^= 1, swap(nodes[rt], ln);
    if (r - l == 1) return;
    if (atLeft) insert(l, m, rt << 1, ln);
    else insert(m, r, rt << 1 | 1, ln);
  }
  int query(int l, int r, int rt, int x) {
    int m = (l + r) >> 1; int ret = -INF;
    if (nodes[rt].id != -1) ret = nodes[rt].at(x);
    if (r - l == 1) return ret;
    if (x < m) return max(ret, query(l, m, rt << 1, x));
    return max(ret, query(m, r, rt << 1 | 1, x));
  }
public:
  LiChao(int n_) : n(n_), nodes(n * 4) {}
  void insert(L ln) { insert(0, n, 1, ln); }
  int query(int x) { return query(0, n, 1, x); }
};