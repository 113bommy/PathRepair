n, k = map(int, input().split())

ans = 0
for b in range(1, n + 1):
    ans += max(b - k, 0) * n // b
    ans += max(0, n % b - k + 1)

if k == 0:
    ans -= n

print(ans)