from bisect import bisect_left as bl
from bisect import bisect_right as br
from heapq import heappush,heappop,heapify
import math
from collections import *
from functools import reduce,cmp_to_key
import sys
input = sys.stdin.readline
M = mod = 998244353
def factors(n):return sorted(set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))
def inv_mod(n):return pow(n, mod - 2, mod)
 
def li():return [int(i) for i in input().rstrip('\n').split()]
def st():return input().rstrip('\n')
def val():return int(input().rstrip('\n'))
def li2():return [i for i in input().rstrip('\n')]
def li3():return [int(i) for i in input().rstrip('\n')]



n = val()
l = li()
l1 = []
for i in range(n):
    for j in range(i + 1,n):
        if l[i] > l[j]:
            l1.append([l[i],i,j])

print(len(l1))

l1.sort(reverse = 1,key = lambda x:(x[-1],x[0],x[1]))
for _,i,j in l1:print(i + 1,j + 1)
