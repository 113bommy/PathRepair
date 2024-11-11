ans = []
for t in range(int(input())):
    n, k = map(int, input().split())
    *a, = map(int, input().split())
    h = {}
    for v in a:
        h[v] = True
    u = len(h)

    if k == 1:
        ans.append(1 if u == 1 else -1)
    else:
        ans.append(1+max(0, u-k)//(k-1))
for a in ans:
    print(a)
