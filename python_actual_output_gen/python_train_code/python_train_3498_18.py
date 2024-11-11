from sys import stdin


def factorize(n):  # o(sqr(n))
    c = 1
    while (c * c <= n and c <= p):
        if n % c == 0:
            return False
        c += 1
    return True


p, n = map(int, stdin.readline().split())
for i in range(n, p, -1):
    if factorize(i):
        exit(print(i))
print(-1)
