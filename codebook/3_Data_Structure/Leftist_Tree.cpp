struct node {
  int v, data, sz, sum;
  node *l, *r;
  node(int k)
    : v(0), data(k), sz(1), l(0), r(0), sum(k) {}
};
int sz(node *p) { return p ? p->sz : 0; }
int V(node *p) { return p ? p->v : -1; }
int sum(node *p) { return p ? p->sum : 0; }
node *merge(node *a, node *b) {
  if (!a || !b) return a ? a : b;
  if (a->data < b->data) swap(a, b);
  a->r = merge(a->r, b);
  if (V(a->r) > V(a->l)) swap(a->r, a->l);
  a->v = V(a->r) + 1, a->sz = sz(a->l) + sz(a->r) + 1;
  a->sum = sum(a->l) + sum(a->r) + a->data;
  return a;
}
void pop(node *&o) {
  node *tmp = o;
  o = merge(o->l, o->r);
  delete tmp;
}
