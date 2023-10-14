// return p4 is strictly in circumcircle of tri(p1,p2,p3)
int sqr(int x) { return x * x; }
bool in_cc(const pii& p1, const pii& p2, const pii& p3, const pii& p4) {
  int u11 = p1.X - p4.X; int u12 = p1.Y - p4.Y;
  int u21 = p2.X - p4.X; int u22 = p2.Y - p4.Y;
  int u31 = p3.X - p4.X; int u32 = p3.Y - p4.Y;
  int u13 = sqr(p1.X) - sqr(p4.X) + sqr(p1.Y) - sqr(p4.Y);
  int u23 = sqr(p2.X) - sqr(p4.X) + sqr(p2.Y) - sqr(p4.Y);
  int u33 = sqr(p3.X) - sqr(p4.X) + sqr(p3.Y) - sqr(p4.Y);
  __int128 det = (__int128)-u13 * u22 * u31 + (__int128)u12 * u23 * u31 + (__int128)u13 * u21 * u32 - (__int128)u11 * u23 * u32 - (__int128)u12 * u21 * u33 + (__int128)u11 * u22 * u33;
  return det > eps;
}
