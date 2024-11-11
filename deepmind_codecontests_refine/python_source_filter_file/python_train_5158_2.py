n, m = map(int, input().split())
ans = n // 5 * 5 * (m // 5)
x = n // 5
y = m // 5
x1 = n % 5
y1 = m % 5
ans += x1 * y + y1 * x
for i in range(1, x1 + 1):
    for j in range(1, y + 1):
            if (i + j) % 5 == 0:
                ans += 1
print(ans)