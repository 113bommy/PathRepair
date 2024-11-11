def a(n):
    if n == 1:
        return 0
    else:
        return (n - 1) * 4 * (n // 2) + a(n - 2)


a = list()

t = int(input())
for _ in range(t):
    n = int(input())
    a.append(0)
    for i in range(3, n + 2, 2):
        a.append((i - 1) * 4 * (i // 2) + a[len(a) - 1])
    print(a[len(a) - 1])

