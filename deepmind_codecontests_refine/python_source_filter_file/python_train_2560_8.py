f = lambda: map(int, input().split())
n, w = f()
t = list(f())
if sum(t) < w: print(-1)
else:
    p = [(a + 1) // 2 for a in t]
    d = w - sum(p)
    if d < 0: print(-1)
    else:
        p = sorted(zip(t, p, range(n)))
        for a, b, i in p[::-1]:
            if d == 0: t[i] = b
            elif a > b + d: d, t[i] = 0, b + d
            else: d -= a - b
    print(' '.join(map(str, t)))