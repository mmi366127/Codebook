typedef pair<double, double> pdd;
typedef pair<pii, pii> Line;
pii operator+(pii a, pii b)
{ return pii(a.X + b.X, a.Y + b.Y); }
pii operator-(pii a, pii b)
{ return pii(a.X - b.X, a.Y - b.Y); }
pii operator*(pii a, int b)
{ return pii(a.X * b, a.Y * b); }
pii operator/(pii a, int b)
{ return pii(a.X / b, a.Y / b); }
pdd operator/(pii a, double b)
{ return pdd(a.X / b, a.Y / b); }
int dot(pii a, pii b)
{ return a.X * b.X + a.Y * b.Y; }
int cross(pii a, pii b)
{ return a.X * b.Y - a.Y * b.X; }
int abs2(pii a)
{ return dot(a, a); }
int sign(int a)
{ return a == 0 ? 0 : a > 0 ? 1 : -1; }
int ori(pii a, pii b, pii c)
{ return sign(cross(b - a, c - a)); }
bool collinearity(pii p1, pii p2, pii p3)
{ return sign(cross(p1 - p3, p2 - p3)) == 0; }
bool btw(pii p1, pii p2, pii p3) {
  if (!collinearity(p1, p2, p3)) return 0;
  return sign(dot(p1 - p3, p2 - p3)) <= 0;
}
bool seg_intersect(pii p1, pii p2, pii p3, pii p4) {
  int a123 = ori(p1, p2, p3);
  int a124 = ori(p1, p2, p4);
  int a341 = ori(p3, p4, p1);
  int a342 = ori(p3, p4, p2);
  if (a123 == 0 && a124 == 0)
    return btw(p1, p2, p3) || btw(p1, p2, p4) ||
      btw(p3, p4, p1) || btw(p3, p4, p2);
  return a123 * a124 <= 0 && a341 * a342 <= 0;
}
pdd intersect(pii p1, pii p2, pii p3, pii p4) {
  int a123 = cross(p2 - p1, p3 - p1);
  int a124 = cross(p2 - p1, p4 - p1);
  return (p4 * a123 - p3 * a124) / double(a123 - a124); // C^3 / C^2
}
pii perp(pii p1)
{ return pii(-p1.Y, p1.X); }
