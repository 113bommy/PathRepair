n, a, b = map(int, input().split(' '))

k = 0
for i in range(1, n + 1):
    if i <= b + 1 and i <= n - a:
        k += 1
print(k)