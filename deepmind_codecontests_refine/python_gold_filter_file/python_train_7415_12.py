import math
from bisect import bisect_left, bisect_right
from sys import stdin, stdout, setrecursionlimit
from collections import Counter
input = lambda: stdin.readline().strip()
print = stdout.write

n, k = map(int, input().split())
ls = list(map(int, input().split()))
ls2 = [(i, ls[i]) for i in range(n)]
ls2.sort(key=lambda x: x[1])
ls2.reverse()
arr = [ls2[i][0] for i in range(k)]
arr.sort()
prod = 1
s = ls[arr[0]]
for i in range(k-1):
    prod = (prod*(arr[i+1]-arr[i]))%998244353
    s+=ls[arr[i+1]]
print(str(s)+' '+str(prod)+'\n')
