n, k = map(int, input().split())
ar = [0] + list(map(int, input().split()))
for i in range(1,n):
    ar[i] += ar[i-1]
ans = 0
for i in range(k):
    a, b = map(int, input().split())
    ans += max(0, ar[b] - ar[a-1])
print(ans)