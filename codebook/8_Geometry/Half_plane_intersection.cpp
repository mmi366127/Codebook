pii area_pair(Line a, Line b) 
{ return pii(cross(a.Y - a.X, b.X - a.X), cross(a.Y - a.X, b.Y - a.X)); }
bool isin(Line l0, Line l1, Line l2) {
  // Check inter(l1, l2) strictly in l0
  auto [a02X, a02Y] = area_pair(l0, l2);
  auto [a12X, a12Y] = area_pair(l1, l2);
  if (a12X - a12Y < 0) a12X *= -1, a12Y *= -1;
  return i128(a02Y) * a12X - i128(a02X) * a12Y > 0;
}
/* Having solution, check size > 2 */
/* --^-- Line.X --^-- Line.Y --^-- */
vector<Line> halfPlaneInter(vector<Line> arr) {
  sort(ALL(arr), [&](Line a, Line b) -> int {
    if (cmp(a.Y - a.X, b.Y - b.X, 0) != -1)
      return cmp(a.Y - a.X, b.Y - b.X, 0);
    return ori(a.X, a.Y, b.Y) < 0;
  });
  deque<Line> dq(1, arr[0]);
  auto pop_back = [&](int t, Line p) {
    while (SZ(dq) >= t && !isin(p, end(dq)[-2], end(dq)[-1])) dq.pb();
  };
  auto pop_front = [&](int t, Line p) {
    while (SZ(dq) >= t && !isin(p, dq[0], dq[1])) dq.pf();
  };
  for (auto p : arr)
    if (cmp(dq.back().Y - dq.back().X, p.Y - p.X, 0) != -1)
      pop_back(2, p), pop_front(2, p), dq.eb(p);
  pop_back(3, dq[0]), pop_front(3, dq.back());
  return vector<Line>(ALL(dq));
}