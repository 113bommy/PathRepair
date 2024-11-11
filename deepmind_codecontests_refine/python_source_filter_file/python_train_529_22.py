import sys
import string
from math import gcd
import getpass
import math
from decimal import Decimal


def ria():
    return [int(i) for i in input().split()]


if getpass.getuser() != 'frohenk':
    filename = 'half'
    # sys.stdin = open('input.txt')
    # sys.stdout = open('output.txt', 'w')
else:
    sys.stdin = open('input.txt')

n, L, a = ria()
lt = 0
suma = 0
for i in range(n):
    t, l = ria()
    suma += (t - lt) // a
    lt = t + l
print((L - lt) // a)
