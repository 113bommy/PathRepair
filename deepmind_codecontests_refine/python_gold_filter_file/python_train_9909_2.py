n = int(input())

d = int(input())
e = int(input())

ans = min(n % d, n%(5*e))

if (d < 5*e):
    T = int(n / (5*e))
    c = 5 * e
    c2 = d
else:
    T = int(n / d)
    c = d
    c2 = 5 * e

for i in range(T + 1):
    ans = min(ans, (n - i * c - c2 * int((n - i * c)/c2)))

print(ans)