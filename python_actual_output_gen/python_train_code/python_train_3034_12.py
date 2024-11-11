n, k, m, d = map(int, input().split())

ans = min(n, m)
for i in range(1, d + 1):
    maxc = min(n // ((i - 1) * k + 1), m)

    if maxc == 0 or ((n // maxc + k - 1) // k) != d:
        continue

    ans = max(ans, i * maxc)

print(ans)
