'''
      ___           ___                         ___                       ___           ___                         ___
     /\__\         /\  \         _____         /\  \                     /\  \         /\  \                       /\__\
    /:/ _/_        \:\  \       /::\  \        \:\  \       ___         /::\  \       |::\  \         ___         /:/ _/_
   /:/ /\  \        \:\  \     /:/\:\  \        \:\  \     /\__\       /:/\:\__\      |:|:\  \       /\__\       /:/ /\  \
  /:/ /::\  \   ___  \:\  \   /:/  \:\__\   ___ /::\  \   /:/__/      /:/ /:/  /    __|:|\:\  \     /:/  /      /:/ /::\  \
 /:/_/:/\:\__\ /\  \  \:\__\ /:/__/ \:|__| /\  /:/\:\__\ /::\  \     /:/_/:/__/___ /::::|_\:\__\   /:/__/      /:/_/:/\:\__\
 \:\/:/ /:/  / \:\  \ /:/  / \:\  \ /:/  / \:\/:/  \/__/ \/\:\  \__  \:\/:::::/  / \:\~~\  \/__/  /::\  \      \:\/:/ /:/  /
  \::/ /:/  /   \:\  /:/  /   \:\  /:/  /   \::/__/       ~~\:\/\__\  \::/~~/~~~~   \:\  \       /:/\:\  \      \::/ /:/  /
   \/_/:/  /     \:\/:/  /     \:\/:/  /     \:\  \          \::/  /   \:\~~\        \:\  \      \/__\:\  \      \/_/:/  /
     /:/  /       \::/  /       \::/  /       \:\__\         /:/  /     \:\__\        \:\__\          \:\__\       /:/  /
     \/__/         \/__/         \/__/         \/__/         \/__/       \/__/         \/__/           \/__/       \/__/

'''
"""
░░██▄░░░░░░░░░░░▄██
░▄▀░█▄░░░░░░░░▄█░░█░
░█░▄░█▄░░░░░░▄█░▄░█░
░█░██████████████▄█░
░█████▀▀████▀▀█████░
▄█▀█▀░░░████░░░▀▀███
██░░▀████▀▀████▀░░██
██░░░░█▀░░░░▀█░░░░██
███▄░░░░░░░░░░░░▄███
░▀███▄░░████░░▄███▀░
░░░▀██▄░▀██▀░▄██▀░░░
░░░░░░▀██████▀░░░░░░
░░░░░░░░░░░░░░░░░░░░
"""
import sys
import math
import collections
import operator as op
from collections import deque
from math import gcd, inf, sqrt, pi, cos, sin, ceil, log2, floor
from bisect import bisect_right, bisect_left, bisect

# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

from functools import reduce
from sys import stdin, stdout, setrecursionlimit
setrecursionlimit(2**20)


def ncr(n, r):
    r = min(r, n - r)
    numer = reduce(op.mul, range(n, n - r, -1), 1)
    denom = reduce(op.mul, range(1, r + 1), 1)
    return numer // denom  # or / in Python 2


def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return (list(factors))


def isPowerOfTwo(x):
    return (x and (not(x & (x - 1))))

MOD = 1000000007
PMOD = 998244353
N = 10**9 + 7
LOGN = 30
alp = 'abcdefghijklmnopqrstuvwxyz'
T = 1
T = int(stdin.readline())
for _ in range(T):
    # n, k = list(map(int, stdin.readline().rstrip().split()))
    n = int(stdin.readline())
    # a = list(map(int, stdin.readline().rstrip().split()))
    # c = list(map(int, stdin.readline().rstrip().split()))
    # s = str(stdin.readline().strip('\n'))
    # b = str(stdin.readline().strip('\n'))
    # m = int(stdin.readline())
    # s = list(map(int, stdin.readline().rstrip().split())
    a = prime_factors(n)
    if len(a) == 1:
        print(1)
        print(n)
        continue
    d = {}
    for i in a:
        if i not in d:
            d[i] = 0
        d[i] += 1
    isOk = False
    for i in d:
        if d[i] != 1:
            isOk = True
    if not isOk:
        print(1)
        print(n)
        continue
    mx = -1
    val = 0
    for i in d:
        if d[i] >= mx:
            mx = d[i]
            val = i
    # print(mx, val)
    # print(mx - 1)
    ans = [val] * (mx - 1)
    ans.append(n // val**(mx - 1))
    print(*ans)
