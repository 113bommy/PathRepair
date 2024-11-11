from bisect import bisect_left as bl
from bisect import bisect_right as br
import heapq
import math
from collections import *
from functools import reduce,cmp_to_key
import sys
input = sys.stdin.readline
 
# M = mod = 998244353
def factors(n):return sorted(list(set(reduce(list.__add__,([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))))
# def inv_mod(n):return pow(n, mod - 2, mod)
 
def li():return [int(i) for i in input().rstrip('\n').split(' ')]
def st():return input().rstrip('\n')
def val():return int(input().rstrip('\n'))
def li2():return [i for i in input().rstrip('\n').split(' ')]
def li3():return [int(i) for i in input().rstrip('\n')]

n = val()
cnt1 = Counter()
cnt2 = Counter()

print('? 1 ' + str(n),flush = True)
le = 0
for i in range(n):
    for j in range(i+1,n+1):le += 1

for j in range(le):
    cnt1[''.join(sorted(st()))] += 1

if n == 1:
    for i in cnt1.keys():
        print('! ' + str(i),flush = True)
        exit()

print('? 2 ' + str(n),flush = True)
le = 0
for i in range(1,n):
    for j in range(i+1,n+1):le += 1
# print(le)
for i in range(le):
    cnt2[''.join(sorted(st()))] += 1

cnt1 -= cnt2
cnt1 = sorted(list(cnt1),key = lambda x:len(x))
s = ''
currcount = Counter()
for i in cnt1:
    currcount = Counter(s)
    for j in i:
        if not currcount[j]:
            s += j
            break
        currcount[j] -= 1
print('! ' + s,flush = True)