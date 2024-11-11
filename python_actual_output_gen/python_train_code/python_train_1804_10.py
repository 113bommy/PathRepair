s = input()
k = 0
ans = 0
vis = set()
for i, c in enumerate(s):
    k += int(c)
    k %= 3
    if k in vis:
        ans += 1
        k = 0
        vis = {0}
    else:
        vis.add(k)
print(ans)