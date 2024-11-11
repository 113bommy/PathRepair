from math import sqrt


def parallelipiped(a, b, c):
    x = sqrt((a * c) // b)
    y = x // a
    z = y // b
    return int(4 * x + 4 * y + 4 * z)


A, B, C = [int(i) for i in input().split()]
print(parallelipiped(A, B, C))
