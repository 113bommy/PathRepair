n, m = map(int, input().split())
r = 0
for a in range(max(n,m)):
    for b in range(max(n,m)):
        if a**2 + b == n and a + b**2 == m:
            r += 1
print(r)
