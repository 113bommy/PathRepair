n, m = map(int, input().split())

count = 0
for b in range(m):
    for a in range(n):
        if a**2 + b == n and a + b**2 == m:
            count += 1

print(count)