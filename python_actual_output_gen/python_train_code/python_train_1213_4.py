n, k = map(int, input().split())
v = list(map(int, input().split()))  # 筒

c = min(n, k)
ans = 0
for a in range(c):
    for b in range(c - a):
        w = v[:a] + v[n-b:]  # 手持ち
        w.sort()
        for i in range(k - (a + b)):
            if len(w) > 0 and w[0] < 0:
                del w[0]
            else:
                break
        ans = max(ans, sum(w))
print(ans)