from sys import *
'''sys.stdin = open('input.txt', 'r')  
sys.stdout = open('output.txt', 'w') '''
from collections import defaultdict as dd
from math import *
from bisect import *
#sys.setrecursionlimit(10 ** 8)
def sinp():
    return input()
def inp():
    return int(sinp())
def minp():
    return map(int, sinp().split())
def linp():
    return list(minp())
def strl():
    return list(sinp())
def pr(x):
    print(x)
mod = int(1e9+7)
n = inp()
a = linp()
m = inp()
b = linp()
d = dd(int)
for i in range(m):
    for j in range(n):
        if b[i] % a[j] == 0:
            d[b[i] // a[j]] += 1
pr(d[max(d.keys())])