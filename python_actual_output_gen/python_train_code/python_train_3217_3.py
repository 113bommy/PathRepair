n = int(input())
a = list(map(int, input().split()))
for i in range(1, n):
    a[i] += a[i - 1]
ans = n
for x in a[:n-1]:
    ans = min(ans, abs(a[n-1] - 2 * x))
print(ans)
