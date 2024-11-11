import sys

stdin = sys.stdin

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(stdin.readline().rstrip())
nm = lambda: map(int, stdin.readline().split())
nl = lambda: list(map(int, stdin.readline().split()))

n,k = nm()
l = nl()
f = list(filter(lambda x:x>0, l))
g = list(filter(lambda x:x<0, l))
f.sort(); g.sort(reverse=True)
pl = len(f); mi = len(g)
ze = n - pl - mi
tomi = pl*mi
if tomi >= k:
    def jud(z):
        ret = 0
        i = mi
        for x in f:
            while i and x*g[i-1] <= z: i -= 1
            ret += mi - i
        return ret
    ok,ng = 0,max(f)*min(g)-1
    while ok - ng > 1:
        mid = (ok+ng)//2
        if jud(mid) < k:
            ng = mid
        else:
            ok = mid
    print(ok)
    exit(0)

tomi += ze*(n-ze) + (ze-1)*ze//2
if tomi >= k:
    print(0); exit(0)

else:
    k -= tomi
    def jud2(z):
        ret = 0
        i = pl
        for e,x in enumerate(f):
            while i and f[i-1]*x > z: i -= 1
            ret += i - (e<=i-1)
        i = mi
        for e,x in enumerate(g):
            while i and g[i-1]*x > z: i -= 1
            ret += i - (e<=i-1)
        return ret//2
    ok,ng = 0,max(max(f)**2, min(g)**2)
    while ng - ok > 1:
        mid = (ok+ng)//2
        if jud2(mid) < k:
            ok = mid
        else:
            ng = mid
    print(ng)
