n, k = map(int, input().split())
*a, = map(int, input().split())
ans = 0
for i in range(1, n):
    d = k - a[i - 1] - a[i]
    ans += d
    a[i] += d
print(ans)
print(*a)

