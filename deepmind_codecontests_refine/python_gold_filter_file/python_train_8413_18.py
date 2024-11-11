from math import sqrt

q = int(input())
query = [tuple(map(int, input().split())) for _ in range(q)]


def sqrtfloor(x):
    s = int(sqrt(x))
    if s ** 2 == x:
        s -= 1
    return s


def solve(a, b):
    a, b = min(a, b), max(a, b)
    if a == b or a + 1 == b:
        return 2 * a - 2
    else:
        s = sqrtfloor(a * b)
        if s * (s + 1) < a * b:
            return 2 * s - 1
        else:
            return 2 * s - 2


for a, b in query:
    print(solve(a, b))
