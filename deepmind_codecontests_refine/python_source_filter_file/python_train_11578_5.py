import sys
from bisect import bisect_left
m, n, k, t = map(int, input().split())
a = sorted(map(int, input().split()))
traps = sorted(list(map(int, l.split())) for l in sys.stdin)

ok, ng = 2*10**5, 0
while ok - ng > 1:
    mid = (ok+ng) // 2
    l, r = 0, 0
    dist = 0
    for i in range(k):
        if mid < traps[i][2]:
            if r < traps[i][0]:
                dist += (r - l) * 2
                l, r = traps[i][0]-1, traps[i][1]
            else:
                r = max(r, traps[i][1])

    dist += (r - l) * 2 + n

    if dist <= t:
        ok = mid
    else:
        ng = mid

print(m - bisect_left(a, ok))