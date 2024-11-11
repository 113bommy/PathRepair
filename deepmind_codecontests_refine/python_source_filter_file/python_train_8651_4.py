# -*- coding:utf-8 -*-

"""

created by shuangquan.huang at 11/13/18
mt19937 mrand(random_device{} ());

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

int gcd(int a, int b) {
  return (b ? gcd(b, a % b) : a);
}

int la, ra, ta;
int lb, rb, tb;

int read() {
  if (scanf("%d%d%d%d%d%d", &la, &ra, &ta, &lb, &rb, &tb) < 6) {
    return false;
  }
  return true;
}

void solve() {
  int g = gcd(ta, tb);
  int l0 = la % g, r0 = l0 + (ra - la);
  int l1 = lb % g, r1 = l1 + (rb - lb);
  int res = 0;
  {
    int l = max(l0, l1), r = min(r0, r1);
    res = max(res, r - l + 1);
  }
  {
    int l = max(l0, l1 + g), r = min(r0, r1 + g);
    res = max(res, r - l + 1);
  }
  {
    int l = max(l0 + g, l1), r = min(r0 + g, r1);
    res = max(res, r - l + 1);
  }
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}

"""

la, ra, ta = map(int, input().split())
lb, rb, tb = map(int, input().split())


def gcd(x, y):
    while y:
        x, y = y, x % y
    
    return x

# [la+ka*ta, ...]
# [lb+kb*tb, ...]

g = gcd(ta, tb)
l0 = la % g
l1 = lb % g
r0 = l0 + ra - la
r1 = lb + rb - lb

res = 0
l = max(l0, l1)
r = min(r0, r1)
res = max(res, r-l+1)

l = max(l0, l1+g)
r = min(r0, r1+g)
res = max(res, r-l+1)

l = max(l0+g, l1)
r = min(r0+g, r1)
res = max(res, r-l+1)

print(res)
    