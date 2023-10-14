#include <unistd.h>
const int S = 65536;
inline char RC() {
  static char buf[S], *p = buf, *q = buf;
  return p == q and (q = (p = buf) + read(0, buf, S)) == buf ? -1 : *p++;
}
inline int RI() {
  static char c; int a;
  while (((c = RC()) < '0' or c > '9') and c != '-' and c != -1);
  if (c == '-') { a = 0;
    while ((c = RC()) >= '0' and c <= '9') a *= 10, a -= c ^ '0'; }
  else { a = c ^ '0';
    while ((c = RC()) >= '0' and c <= '9') a *= 10, a += c ^ '0'; }
  return a;
}
