void hull(vector<pii> &dots) { // n=1 => ans = {}
  sort(dots.begin(), dots.end());
  vector<pii> ans(1, dots[0]);
  for (int ct = 0; ct < 2; ++ct, reverse(ALL(dots)))
    for (int i = 1, t = SZ(ans); i < SZ(dots); ans.eb(dots[i++]))
      while (SZ(ans) > t && ori(ans[SZ(ans) - 2], ans.back(), dots[i]) <= 0) 
        ans.pb();
  ans.pb(), ans.swap(dots);
}
