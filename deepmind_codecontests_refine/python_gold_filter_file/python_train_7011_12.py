n, m = map(int, input().split())
a = 0
for i in range(0, max(n, m) + 1):
    for j in range(0, max(n, m) + 1):
        if i ** 2 + j == n and j ** 2 + i == m:
            a += 1
print(a)
