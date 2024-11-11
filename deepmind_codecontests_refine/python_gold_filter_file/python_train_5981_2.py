#!/usr/bin/python3
from array import array
n = int(input())
a = [int(v) for v in input().split()]
#a = array("l")
#a.fromlist(t)
s = 0
k = sum(a)
m = int(k/n)
for i in range(n-1):
    d = m - a[i]
    a[i] = m
    a[i+1] -= d
    s += abs(d)
print(s)
