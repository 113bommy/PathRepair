from sys import stdin
import math

n, m = map(int, stdin.readline().split())

k = n - m
if k == 0:
    print (m)
elif m <= k:
    print(m + 1)
else:
    print(m - 1)