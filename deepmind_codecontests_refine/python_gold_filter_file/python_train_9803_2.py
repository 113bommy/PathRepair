n = int(input())
a = [0 for _ in range(n)]

k = 0
for d in range(2, n + 1):
    if a[d - 1] == 0:
        k += 1
        for i in range(1, n // d + 1):
            a[d * i - 1] = k

print(*a[1:])
