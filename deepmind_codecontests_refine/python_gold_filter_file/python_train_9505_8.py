import sys
import re
import random
import math
import copy
from heapq import heappush, heappop, heapify
from functools import cmp_to_key
from bisect import bisect_left, bisect_right
from collections import defaultdict, deque, Counter
# sys.setrecursionlimit(1000000)

# input aliases
input = sys.stdin.readline
getS = lambda: input().strip()
getN = lambda: int(input())
getList = lambda: list(map(int, input().split()))
getZList = lambda: [int(x) - 1 for x in input().split()]

INF = float("inf")
MOD = 10**9 + 7
divide = lambda x: pow(x, MOD-2, MOD)


def nck(n, k, kaijyo):
    return (npk(n, k, kaijyo) * divide(kaijyo[k])) % MOD

def npk(n, k, kaijyo):
    if k == 0 or k == n:
        return n % MOD
    return (kaijyo[n] * divide(kaijyo[n-k])) % MOD

def fact_and_inv(SIZE):
    inv = [0] * SIZE  # inv[j] = j^{-1} mod MOD
    fac = [0] * SIZE  # fac[j] = j! mod MOD
    finv = [0] * SIZE  # finv[j] = (j!)^{-1} mod MOD
    inv[1] = 1
    fac[0] = fac[1] = 1
    finv[0] = finv[1] = 1
    for i in range(2, SIZE):
        inv[i] = MOD - (MOD // i) * inv[MOD % i] % MOD
        fac[i] = fac[i - 1] * i % MOD
        finv[i] = finv[i - 1] * inv[i] % MOD

    return fac, finv

def renritsu(A, Y):
    # example 2x + y = 3, x + 3y = 4
    # A = [[2,1], [1,3]])
    # Y = [[3],[4]] または [3,4]
    A = np.matrix(A)
    Y = np.matrix(Y)
    Y = np.reshape(Y, (-1, 1))
    X = np.linalg.solve(A, Y)

    # [1.0, 1.0]
    return X.flatten().tolist()[0]

class TwoDimGrid:
    # 2次元座標 -> 1次元
    def __init__(self, h, w, wall="#"):
        self.h = h
        self.w = w
        self.size = (h+2) * (w+2)
        self.wall = wall
        self.get_grid()
        # self.init_cost()

    def get_grid(self):
        grid = [self.wall * (self.w + 2)]
        for i in range(self.h):
            grid.append(self.wall + getS() + self.wall)

        grid.append(self.wall * (self.w + 2))
        self.grid = grid
    def init_cost(self):
        self.cost = [INF] * self.size

    def pos(self, x, y):
        # 壁も含めて0-indexed 元々の座標だけ考えると1-indexed
        return y * (self.w + 2) + x
    def getgrid(self, x, y):
        return self.grid[y][x]
    def get(self, x, y):
        return self.cost[self.pos(x, y)]
    def set(self, x, y, v):
        self.cost[self.pos(x, y)] = v
        return
    def show(self):
        for i in range(self.h+2):
            print(self.cost[(self.w + 2) * i:(self.w + 2) * (i+1)])
    def showsome(self, tgt):
        for t in tgt:
            print(t)
        return
    def showsomejoin(self, tgt):
        for t in tgt:
            print("".join(t))
        return

    def search(self):
        grid = self.grid
        move = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        move_eight = [(0, 1), (0, -1), (1, 0), (-1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1)]
        # for i in range(1, self.h+1):
        #     for j in range(1, self.w+1):
        #         cx, cy = j, i
        #         for dx, dy in move:
        #             nx, ny = dx + cx, dy + cy


class BIT():
    # A1 ... AnのBIT(1-indexed)
    def __init__(self, n):
        self.n = n
        self.BIT = [0] * (n + 2)

    # A1 ~ Aiまでの和 O(logN)
    def query(self, idx):
        res_sum = 0
        while idx > 0:
            res_sum += self.BIT[idx]
            idx -= idx & (-idx)
        return res_sum

    # Ai += x O(logN)
    def update(self, idx, x):
        # print(idx)
        while idx <= self.n:
            # print(idx)
            self.BIT[idx] += x
            idx += idx & (-idx)
        return

    def show(self):
        print(self.BIT)


def solve():
    n, m = getList()

    graph = [getS() for i in range(n)]

    if (m % 2 == 1):
        ans = []
        for i in range(m+1):
            if (i % 2 == 0):
                ans.append(1)
            else:
                ans.append(2)
        print("YES")
        print(*ans)
        return

    if (n == 2):
        if graph[0][1] != graph[1][0]:
            print("NO")
            return
        else:
            ans = []
            for i in range(m + 1):
                if (i % 2 == 0):
                    ans.append(1)
                else:
                    ans.append(2)
            print("YES")
            print(*ans)
            return

    anses = []
    for i in range(n):
        for j in range(n):
            if i == j:
                continue
            if graph[i][j] == graph[j][i]:
                anses = [i, j]
                break

    if anses:
        ans = []
        for i in range(m + 1):
            ans.append(anses[i % 2] + 1)
        print("YES")
        print(*ans)
        return

    if graph[0][1] == graph[1][2]:
        if graph[1][2] == graph[2][0]:
            ans = []
            for i in range(m + 1):
                ans.append((i % 3) + 1)
            print("YES")
            print(*ans)
            return

        else:
            p4 = [2,3,2,1]
            p6 = [1,2,3,2]

    else:
        if graph[0][2] == graph[0][1]:
            p4 = [3, 2, 3, 1]
            p6 = [1, 3, 2, 3]
        else:
            p4 = [1, 2, 1, 3]
            p6 = [3, 1, 2, 1]


    if m % 4 == 0:
        ans = []
        for i in range(m + 1):
            ans.append(p4[i%4])
        print("YES")
        print(*ans)
        return

    else:
        ans = []
        for i in range(m + 1):
            ans.append(p6[i%4])
        print("YES")
        print(*ans)
        return

def main():
    n = getN()
    for _ in range(n):
        solve()

    return
if __name__ == "__main__":
    main()
    # solve()