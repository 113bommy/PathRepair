# Author: $%U%$
# Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$

import io
import os
import collections
import math
import functools
import itertools
import bisect
import heapq
from sys import stdin, stdout, stderr
from collections import *
from math import *
from functools import *
from itertools import *
from heapq import *
from bisect import bisect_left, bisect_right, insort_left, insort_right

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
def get_ints(): return list(map(int, input().split()))
def get_int(): return int(input())
def get_str(): return "".join(list(map(chr, input()))[:-1])
def eprint(*args): stderr.write(", ".join(map(str, args)) + "\n")
def print(*args): stdout.write(" ".join(map(str, args)) + "\n")

# **************************************************************************** #


t = get_int()
for tt in range(t):
    n, m, hor = get_ints()
    total = (n * m) // 2
    vert = total - hor
    h_forced = v_forced = 0
    both = (((n // 2) * 2) * ((m // 2) * 2)) // 2
    if n % 2 == 1:
        h_forced = m // 2
    elif m % 2 == 1:
        v_forced = n // 2

    if h_forced > hor or v_forced > vert:
        print("NO")
        continue

    hor -= h_forced
    vert -= v_forced
    if hor % 2 == 1 or vert % 2 == 1:
        print("NO")
        continue

    print("YES")
    grid = [['a'] * m for _ in range(n)]
    if n % 2 == 1:
        char = "x"
        for x in range(0, m, 2):
            grid[-1][x] = grid[-1][x + 1] = char
            if char == "x":
                char = "y"
            else:
                char = "x"
    if m % 2 == 1:
        char = "x"
        for y in range(0, n, 2):
            grid[y][-1] = grid[y + 1][-1] = char
            if char == "x":
                char = "y"
            else:
                char = "x"

    hchars = ["q", "w", "e", "r", "t", "z", "u", "i"]
    vchars = ["a", "s", "d", "f", "g", "h", "j", "k"]
    ci = 0
    for y in range(n // 2):
        for x in range(m // 2):
            if hor:
                if y % 2 == 0 and x % 2 == 0:
                    c1, c2 = hchars[0], hchars[1]
                elif y % 2 == 1 and x % 2 == 0:
                    c1, c2 = hchars[2], hchars[3]
                elif y % 2 == 0 and x % 2 == 1:
                    c1, c2 = hchars[4], hchars[5]
                elif y % 2 == 1 and x % 2 == 1:
                    c1, c2 = hchars[6], hchars[7]
                grid[2 * y][2 * x] = grid[2 * y][2 * x + 1] = c1
                grid[2 * y + 1][2 * x] = grid[2 * y + 1][2 * x + 1] = c2
                hor -= 2
            else:
                if y % 2 == 0 and x % 2 == 0:
                    c1, c2 = vchars[0], vchars[1]
                elif y % 2 == 1 and x % 2 == 0:
                    c1, c2 = vchars[2], vchars[3]
                elif y % 2 == 0 and x % 2 == 1:
                    c1, c2 = vchars[4], vchars[5]
                elif y % 2 == 1 and x % 2 == 1:
                    c1, c2 = vchars[6], vchars[7]
                grid[2 * y][2 * x] = grid[2 * y + 1][2 * x] = c1
                grid[2 * y][2 * x + 1] = grid[2 * y + 1][2 * x + 1] = c2

    for row in grid:
        print("".join(row))
