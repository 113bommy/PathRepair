n, m = map(int, input().split())

count = 0
for b in range(m+1):
    for a in range(n+1):
        if a**2 + b == n and a + b**2 == m:
            count += 1

print(count)