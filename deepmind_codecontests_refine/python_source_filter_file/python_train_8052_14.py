from bisect import bisect_left as bl
from bisect import bisect_right as br
import heapq
import math
from collections import *
from functools import reduce,cmp_to_key
import sys
input = sys.stdin.readline
 
# M = mod = 998244353
# def factors(n):return sorted(set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))
# def inv_mod(n):return pow(n, mod - 2, mod)
 
def li():return [int(i) for i in input().rstrip('\n').split()]
def st():return input().rstrip('\n')
def val():return int(input().rstrip('\n'))
def li2():return [i for i in input().rstrip('\n').split(' ')]
def li3():return [int(i) for i in input().rstrip('\n')]


n = val()
x = val()
curr = x
for i in range(n):
    try:
        curr = 7 - curr
        numbersleft = set([1,2,3,4,5,6])
        numbersleft.remove(curr)
        numbersleft.remove(7-curr)
        a,b = li()
        numbersleft.remove(a)
        numbersleft.remove(7-a)
        numbersleft.remove(b)
        numbersleft.remove(7-b)
    except:
        print('No')
        exit()
print('Yes')
