def ii():
    return int(input())
def mi():
    return map(int, input().split())
def li():
    return list(mi())
import math

la, ra, ta = mi()
lb, rb, tb = mi()
if la > lb:
    la, ra, ta, lb, rb, tb = lb, rb, tb, la, ra, ta
lb -= la
ra -= la
rb -= la
dif = math.gcd(ta, tb)
difl = lb

off1 = difl % dif
ans1 = min(ra, off1 + rb - lb) - max(0, off1) + 1
off2 = off1 - dif
ans2 = min(ra, off2 + rb - lb) - max(0, off2) + 1
ans = max(ans1, ans2)
print(ans)
