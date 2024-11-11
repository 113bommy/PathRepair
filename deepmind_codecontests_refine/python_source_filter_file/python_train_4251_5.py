N, M = map(int, input().split())

def factorized(M):
    d = 2
    f = []
    while d <= M:
        count = 0
        while M % d == 0:
            M //= d
            count += 1
        if count > 0:
            f.append(count)
        d += 1
    return f

def tetra(n, m):
    x = 1
    for y in range(1, n):
        x = x * (m + y - 1) // y
    return x

x = 1
for f in factorized(M):
    x *= tetra(N, f + 1)
    x %= 10 ** 9 + 7

print(x)
