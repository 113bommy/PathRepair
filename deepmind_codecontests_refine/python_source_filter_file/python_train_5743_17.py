import math
from collections import deque, defaultdict
from sys import stdin, stdout
from copy import deepcopy
input = stdin.readline
# print = stdout.write
def check(a):
    for i in range(n-1):
        for j in range(m):
            if a[i][j]>=a[i+1][j]:
                return 1
    for i in range(n):
        for j in range(m-1):
            if a[i][j]>=a[i][j+1]:
                return 1
    return 0
listin = lambda : list(map(int, input().split()))
mapin = lambda : map(int, input().split())
n, m = mapin()
a = []
for i in range (n):
    a.append(listin())
b = []
for i in range (n):
    b.append(listin())
for i in range(n):
    for j in range(m):
        if a[i][j] > b[i][j]:
            a[i][j], b[i][j] = b[i][j], a[i][j]
if check(a) or check(b):
    print("Impossbile")
else:
    print("Possible")