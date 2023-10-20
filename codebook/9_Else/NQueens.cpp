void solve(vector<int> &ret, int n) { // no sol when n=2,3
  if (n % 6 == 2) {
    for (int i = 2; i <= n; i += 2) ret.eb(i);
    ret.eb(3); ret.eb(1);
    for (int i = 7; i <= n; i += 2) ret.eb(i);
    ret.eb(5);
  } else if (n % 6 == 3) {
    for (int i = 4; i <= n; i += 2) ret.eb(i);
    ret.eb(2);
    for (int i = 5; i <= n; i += 2) ret.eb(i);
    ret.eb(1); ret.eb(3);
  } else {
    for (int i = 2; i <= n; i += 2) ret.eb(i);
    for (int i = 1; i <= n; i += 2) ret.eb(i);
  }
}
