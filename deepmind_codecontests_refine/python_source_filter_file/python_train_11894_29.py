from math import *


def solver():
    n = int(input())
    if n in [1, 2, 3]:
        print(-1)
        return
    s = []
    for i in range(n + n % 2, 5, -2):
        s.append(i)
    s.extend([2, 4])
    for i in range(1, n + 1 - n % 2 + 1, 2):
        s.append(i)
    print(' '.join(map(str, s[::-1])))


for _ in range(int(input())):
    solver()
