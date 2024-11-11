import sys
from collections import defaultdict
from queue import deque
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10**8)


def geta(fn=lambda s: s.decode()):
    return map(fn, readline().split())


def gete(fn=lambda s: s.decode()):
    return fn(readline().rstrip())


import math


def arg(x, y):
    c = x / math.sqrt(x * x + y * y)
    t = math.acos(c)

    if y < 0:
        t = 2 * math.pi - t

    return t


def dist2(x, y):
    return x * x + y * y


def main():
    N = gete(int)
    E = []
    for _ in range(N):
        x, y = geta(int)
        if x != 0 or y != 0:
            E.append((arg(x, y), x, y))

    E.sort()
    N = len(E)

    ans2 = 0
    for i in range(N):
        j = i
        px, py = (0, 0)
        _, qx, qy = E[i]
        c = 0
        while c < N and dist2(px, py) <= dist2(qx, qy):
            j += 1
            c += 1
            px, py = qx, qy
            _, ex, ey = E[j % N]
            qx, qy = px + ex, py + ey

        tmp = dist2(px, py)

        if ans2 < tmp:
            ans2 = tmp

    print(math.sqrt(ans2))

    ans = 0


if __name__ == "__main__":
    main()