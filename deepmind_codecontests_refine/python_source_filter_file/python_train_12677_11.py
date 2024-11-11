n, m, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = [0] + list(reversed(b)) + a
for i in range(n + m):
    c[i + 1] += c[i]
r = m
ans = 0
for l in range(n + m):
    while r <= n + m and c[r] - c[l] <= k:
        ans = max(ans, r - l)
        r += 1
print(ans)
