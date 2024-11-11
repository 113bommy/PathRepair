from math import sqrt


def parallelipiped(a, b, c):
    x = sqrt((a * c) // b)
    y = a // x
    z = b // y
    return int(4 * x + 4 * y + 4 * z)


A, B, C = [int(i) for i in input().split()]
print(parallelipiped(A, B, C))
