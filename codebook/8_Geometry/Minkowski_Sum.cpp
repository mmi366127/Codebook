vector<pii> Minkowski(vector<pii> A, vector<pii> B) {
  hull(A), hull(B);
  vector<pii> C(1, A[0] + B[0]), s1, s2; 
  for (int i = 0; i < SZ(A); ++i) 
    s1.eb(A[(i + 1) % SZ(A)] - A[i]);
  for (int i = 0; i < SZ(B); i++) 
    s2.eb(B[(i + 1) % SZ(B)] - B[i]);
  for (int i = 0, j = 0; i < SZ(A) || j < SZ(B);)
    if (j >= SZ(B) || (i < SZ(A) && cross(s1[i], s2[j]) >= 0))
      C.eb(B[j % SZ(B)] + A[i++]);
    else
      C.eb(A[i % SZ(A)] + B[j++]);
  return hull(C), C;
}
