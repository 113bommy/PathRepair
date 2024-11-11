from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from string import ascii_lowercase
from functools import lru_cache
import sys
sys.setrecursionlimit(10000)
INF = float("inf")
YES, Yes, yes, NO, No, no = "YES", "Yes", "yes", "NO", "No", "no"
dy4, dx4 = [0, 1, 0, -1], [1, 0, -1, 0]
dy8, dx8 = [0, -1, 0, 1, 1, -1, -1, 1], [1, 0, -1, 0, 1, 1, -1, -1]


def inside(y, x, H, W):
    return 0 <= y < H and 0 <= x < W


def ceil(a, b):
    return (a + b - 1) // b


# aとbの最大公約数
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


# aとbの最小公倍数
def lcm(a, b):
    g = gcd(a, b)
    return a / g * b


def func(X, Y, D):
    ans = ""
    x, y = 0, 0
    for i in range(len(D)):
        d = D[i]

        best_j = 0
        best = INF
        for j in range(4):
            nx, ny = x + dx4[j] * d - X, y + dy4[j] * d - Y
            if abs(nx) + abs(ny) < best:
                best = abs(nx) + abs(ny)
                best_j = j

        x, y = x + dx4[best_j] * d, y + dy4[best_j] * d
        ans += "RULD"[best_j]

    assert(x == X and y == Y)
    return ans[::-1]


def main():
    N = int(input())
    points = []
    for i in range(N):
        X, Y = map(int, input().split())
        points.append((X, Y))

    for i in range(len(points) - 1):
        x1, y1 = points[i]
        x2, y2 = points[i + 1]
        if (x1 + y1) % 2 != (x2 + y2) % 2:
            print("-1")
            return

    D = [2 ** i for i in range(33)][::-1]
    if sum(points[0]) % 2 == 0:
        D.append(1)

    print(len(D))
    print(*D)

    for x, y in points:
        print(func(x, y, D))


if __name__ == '__main__':
    main()
