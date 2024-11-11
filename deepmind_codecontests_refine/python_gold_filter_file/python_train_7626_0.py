import sys

T = int(sys.stdin.readline().strip())
for t in range (0, T):
    p, f = list(map(int, sys.stdin.readline().strip().split()))
    ns, nw = list(map(int, sys.stdin.readline().strip().split()))
    s, w = list(map(int, sys.stdin.readline().strip().split()))
    if s > w:
        s, w = w, s
        ns, nw = nw, ns
    ans = 0
    for ps in range (0, ns+1):
        if ps * s <= p:
            pw = min(nw, (p - ps * s) // w)
            fs = min(ns - ps, f // s)
            fw = min((f - fs * s) // w, nw - pw)
            ans = max(ans, ps + pw + fs + fw)
    print(ans)