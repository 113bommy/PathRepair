# Codeforces: 609B - The Best Gift

n, m = map(int, input().split())
a = list(map(int, input().split()))

cnt = [0] * m
for i in range(n):
    cnt[a[i] - 1] += 1
ans = 0
for i in range(m):
    x = cnt[a[i] - 1]
    ans += x * (n - x)

print(ans // 2)