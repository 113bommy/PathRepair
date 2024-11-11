n, m = map(int, input().split())
v = []
for i in range(m):
    v.append(list(map(int, input().split())))
ans = []
for i in range(1, 100):
    o = True
    for p in v:
        if (p[0] - 1) // i != p[1] - 1:
            o = False
            break
    if o:
        if not(((n - 1) // i + 1) in ans):
            ans.append(((n - 1) // i + 1))
if len(ans) == 1:
    print(ans[0])
else:
    print(-1)
