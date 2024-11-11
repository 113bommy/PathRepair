"""
  ____          _      _____
 / ___|___   __| | ___|  ___|__  _ __ ___ ___  ___
| |   / _ \ / _` |/ _ \ |_ / _ \| '__/ __/ _ \/ __|
| |__| (_) | (_| |  __/  _| (_) | | | (_|  __/\__ \
 \____\___/ \__,_|\___|_|  \___/|_|  \___\___||___/

"""
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
from collections import deque

#sys.stdin = open('input.txt', 'r')
#sys.stdout = open('output.txt', 'w')

from functools import reduce
from sys import stdin, stdout, setrecursionlimit
setrecursionlimit(2**20)


def factors(n):
    return list(set(reduce(list.__add__, ([i, n // i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))

# for _ in range(int(stdin.readline())):
#n = int(stdin.readline().strip('\n'))
# b = str(stdin.readline().strip('\n'))
# n, m = list(map(int, stdin.readline().split()))
#a = list(stdin.readline().strip('\n'))
#b = list(stdin.readline().strip('\n'))
# n = len(a)
# a = list(map(int, stdin.readline().split()))
n, k, l, c, d, p, nl, np = list(map(int, stdin.readline().split()))
print(min((k * l) / nl, (c * d), p // np) // n)
