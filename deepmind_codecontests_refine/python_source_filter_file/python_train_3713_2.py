n, k = map(int, input().split())
p = map(int, input().split())
ans = [0 for i in range(n)]
f = [-1 for i in range(256)]
i = -1
for x in p:
    i += 1
    if f[x] < 0:
        l = x
        while l > 0 > f[l - 1] and x - l < k:
            l -= 1
        if l > 0 and x - f[l - 1] < k and f[l - 1] >= 0:
            f[x] = f[l - 1]
        else:
            f[x] = l
        for j in range(l, x):
            f[j] = f[x]
    ans[i] = f[x]
for x in ans:
    print(x, end=' ')
