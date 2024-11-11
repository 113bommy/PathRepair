q = int(input())
for i in range(q):
    n, m = map(int, input().split())
    s = 0
    els = []
    for i in range(1, 11):
        v = (i * m)
        if v <= n:
            vv = v % 10
            s += vv
            els.append(vv)
        else:
            print(s)
            break
    else:
        times = (n // m) // 10
        sub = (n // m) % 10
        print(times * s + sum(els[:sub]))
