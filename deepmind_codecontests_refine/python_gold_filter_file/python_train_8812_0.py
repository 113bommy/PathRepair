n, k, M, D = list(map(int, input().split()))
mx = 0
for d in range(1, D + 1):
    x = n // (k * d - k + 1)
    x = min(x, M)
    ans = x * d
    mx = max(mx, ans)
print(mx)