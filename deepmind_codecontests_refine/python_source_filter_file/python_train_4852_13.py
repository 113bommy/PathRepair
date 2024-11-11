from math import inf


def mnogougolnik(n, a):
    if n == 3:
        return 1, 2, 3
    ugol, dist, result = 180 / n, inf, 0
    for i in range(1, n):
        cur = ugol * i
        if abs(cur - a) < dist:
            dist, result = abs(cur - a), i + 1
    return 1, n, result


N, A = [int(i) for i in input().split()]
print(*mnogougolnik(N, A))
