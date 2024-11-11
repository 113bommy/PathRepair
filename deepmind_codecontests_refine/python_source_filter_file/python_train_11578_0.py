import sys

readline = sys.stdin.readline
readlines = sys.stdin.readlines
ns = lambda: readline().rstrip()
ni = lambda: int(readline().rstrip())
nm = lambda: map(int, readline().split())
nl = lambda: list(map(int, readline().split()))
prn = lambda x: print(*x, sep='\n')


def gcd(u, v):
    while v:
        u, v = v, u%v
    return u

def solve():
    m, n, k, t = nm()
    a = nl()
    trap = [tuple(nm()) for _ in range(k)]
    idx = 0
    trap.sort()
    ok = max(a) + 1
    ng = -1
    while ok - ng > 1:
        mid = (ok + ng) // 2
        imos = [0]*(n+1)
        ctp = list()
        for l, r, d in trap:
            if d <= mid: continue
            if not ctp or ctp[-1][1] < l:
                ctp.append([l, r])
            else:
                ctp[-1][1] = max(ctp[-1][1], r)
        cost = n + 1
        for l, r in ctp:
            cost += (r - l + 1) * 2
        print(mid, ctp, cost)
        if cost > t:
            ng = mid
        else:
            ok = mid
    print(sum(1 for x in a if x >= ok))
    return

solve()

# T = ni()
# for _ in range(T):
#     solve()
