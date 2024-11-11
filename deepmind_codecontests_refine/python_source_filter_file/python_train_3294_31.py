import getpass
import sys
import math


def ria():
    return [int(i) for i in input().split()]


files = True

if getpass.getuser() == 'frohenk' and files:
    sys.stdin = open("test.in")

t = ria()[0]
for kekas in range(t):
    n, k = ria()
    ar = ria()
    maxi = max(ar[0], n - ar[len(ar) - 1] + 1)
    for j in range(1, k):
        maxi = max(maxi, math.floor((ar[j] - ar[j - 1]) / 2))
    print(maxi)
