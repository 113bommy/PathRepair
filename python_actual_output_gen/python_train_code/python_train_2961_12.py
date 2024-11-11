def f(n):
    if n < 0:
        return -float('inf')
    if n == 0:
        return 0

    if n % 4 == 1:
        return 1 + f(n - 9)
    if n % 4 == 2:
        return 1 + f(n - 6)
    if n % 4 == 3:
        return 1 + f(n - 13)
    return n // 4

q = int(input())
for _ in range(q):
    n = int(input())
    c = f(n)
    if c < 0:
        c = -1
    print(c)
