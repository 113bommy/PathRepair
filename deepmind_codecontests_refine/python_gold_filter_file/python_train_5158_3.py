n, m = map(int, input().split())

ans = 5 * (n // 5) * (m // 5)

for i in range(n % 5):
    ans += m // 5
for i in range(m % 5):
    ans += n // 5

r1, r2 = n % 5, m % 5

for i in range(1, r1+1):
    if i + r2 >= 5:
        ans += 1
print(ans)
