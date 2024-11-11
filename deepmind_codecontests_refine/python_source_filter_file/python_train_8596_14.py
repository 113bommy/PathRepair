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
from math import gcd, inf, sqrt, pi, cos, sin, ceil, log2
from bisect import bisect_right, bisect_left

# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

from functools import reduce
from sys import stdin, stdout, setrecursionlimit
setrecursionlimit(2**20)


def factorial(n):
    if n == 0:
        return 1
    return (n * factorial(n - 1))


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


def sumDigits(no):
    return 0 if no == 0 else int(no % 10) + sumDigits(int(no / 10))

MOD = 1000000007
PMOD = 998244353
N = 10**5
T = 1
# T = int(stdin.readline())
for _ in range(T):
    n, k = list(map(int, stdin.readline().rstrip().split()))
    # n = int(stdin.readline())
    a = list(map(int, stdin.readline().rstrip().split()))
    b = list(map(int, stdin.readline().rstrip().split()))
    # s = list(stdin.readline().strip('\n'))
    # a = list(stdin.readline().strip('\n'))
    # q = int(stdin.readline())
    # s = list(map(int, stdin.readline().rstrip().split()))
    ans = 0
    for i in range(n):
        if a[i] <= b[i]:
            ans += a[i]
            k -= 1
        else:
            ans += b[i]
    d = [0] * n
    for i in range(n):
        d[i] = a[i] - b[i]
    d.sort()
    for i in range(n):
        if d[i] >= 0:
            break
    # print(d)
    # print(k)
    while k > 0:
        ans += d[i]
        i += 1
        k -= 1
    print(ans)
