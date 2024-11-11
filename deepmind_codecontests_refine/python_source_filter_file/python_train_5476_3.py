I = lambda: map(int, input().split())
n, m = I()
l = list(I())

res = [0] * (n + 1)
for i in range(m-1):
    new = (l[i+1] - l[i]) if l[i+1] - l[i] > 0 else (l[i+1] - l[i] + n)
    if res[l[i]] and res[l[i]] != new:
        print(-1)
        exit(0)
    else:
        res[l[i]] = new

wo0 = list(filter((0).__ne__, res))
if len(wo0) == len(set(wo0)):
    rest = set(range(1, n+1)) - set(wo0)
    res.pop(0)
    for x in rest:
        res[res.index(0)] = x
    print(res[1:])
else:
    print(-1)

