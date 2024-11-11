n, m = map(int, input().split())
count = 0

for a in range(0, max(n,m)):
    for b in range(0, max(n, m)):
        if a ** 2 + b == n and a + b ** 2 == m:
            count += 1
print(count)
