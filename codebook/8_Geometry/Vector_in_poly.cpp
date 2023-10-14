// ori(a, b, c) >= 0, valid: "strict" angle from a-b to a-c
bool btwangle(pii a, pii b, pii c, pii p, int strict) {
  return ori(a, b, p) >= strict && ori(a, p, c) >= strict;
}
// whether vector{cur, p} in counter-clockwise order prv, cur, nxt
bool inside(pii prv, pii cur, pii nxt, pii p, int strict) {
  if (ori(cur, nxt, prv) >= 0)
    return btwangle(cur, nxt, prv, p, strict);
  return !btwangle(cur, prv, nxt, p, !strict);
}
