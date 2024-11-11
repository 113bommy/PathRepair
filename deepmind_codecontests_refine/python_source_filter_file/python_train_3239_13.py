n, m = map(int, input().split())

mn = max(0, (n + 1) // 2 - m)

for i in range(n + 1):
    if i * (i - 1) // 2 >= m:
        mx = n - i
        break

print(mn, mx)