import sys
from collections import deque
input = sys.stdin.buffer.readline

T = int(input())
for _ in range(T):
    n, k = map(int, input().split())

    def get_num(u, dw):
        dg, cc = [], 0
        while u:
            d = min(u, 8 if cc==dw else 9)
            u -= d
            dg.append(str(d))
            cc += 1
        return ''.join(reversed(dg))
    
    def check(sm, lv, ln, rn):
        rm = sm - (lv*ln)
        if rm < 0 or rm % rn: return (0, 0)
        rv = rm // rn
        if rv > lv:
            if rv != lv+1: return (0, 0)
            return (1, get_num(lv, 0 if lv==9 else -1))
        else:
            d = lv-rv
            if d < 8 or (d-8) % 9: return (0, 0)
            return (1, get_num(lv, d//9+1))

    can = []
    for r in range(10):
        sm = n
        if r+k < 10:
            sm -= (k+1)*(r+r+k)//2
            if sm >= 0 and sm % (k+1) == 0:
                can.append(get_num(sm//(k+1), -1) + str(r))
        else:
            ln, rn = 10-r, r+k-9
            sm -= ln*(r+9)//2 + rn*(rn-1)//2
            if sm >= 0:
                for lv in range(n+1):
                    ok, u = check(sm, lv, ln, rn)
                    if ok: can.append(u + str(r))
                    if ok: print(sm, r, lv, ln, rn)

    #print(can)
    if not can: print(-1); continue
    mn = min([len(u) for u in can])
    mn = [u for u in can if len(u) == mn]
    mn.sort()
    print(mn[0])

