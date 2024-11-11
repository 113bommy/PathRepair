#!/usr/bin/env python3
import sys

def rint():
    return map(int, sys.stdin.readline().split())
#lines = stdin.readlines()

a1 = int(input())
a2 = int(input())
k1 = int(input())
k2 = int(input())
n = int(input())

if k1 < k2:
    k1, k2 = k2, k1
    a1, a2 = a2, a1

#print(k1, k2, a1, a2)
#k1 >= k2
n_ori = n
#min
tmp = a1*(k1-1) + a2*(k2-1)
n -= tmp
min_v = min(a1+a2, n)

n = n_ori

p = n//k2
if a2 < p:
    p = a2
    n -= p*k2
else:
    n -= p*k2
if n > 0:
    tmp = n//k1
    if tmp > a1:
        tmp = a1
    p+= tmp
max_v = p

print(min_v, max_v)


