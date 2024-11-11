from sys import stdin
from collections import Counter, deque
input = stdin.buffer.readline

T = int(input())
for _ in range(T):
    n, mon = int(input()), list(map(int, input().split()))
    m, hro = int(input()), []
    for _ in range(m):
        p, s = map(int, input().split())
        hro.append((s, p))

    hro.sort(reverse=True)
    ls = []
    for s, p in hro:
        if not ls or p > ls[-1][1]:
            ls.append((s, p))
    hro, m = list(reversed(ls)), len(ls)
    if max(mon) > hro[0][1]: print(-1); continue

    day = 0
    dur, pwr, p, mx = *hro[0], 0, 0
    for u in mon:
        mx = max(mx, u)
        if dur > 0 and pwr >= mx:
            dur -= 1
            continue
        if dur == 0 and p+1 < m and hro[p+1][1] >= mx:
            ndur, npwr, cdur = *hro[p+1], hro[p][0]
            dur, pwr, p = ndur-cdur-1, npwr, p+1
            continue

        day += 1
        dur, pwr, p, mx = hro[0][0]-1, hro[0][1], 0, u

    print(day+1)
            
        


