#!/usr/bin python3
# -*- coding: utf-8 -*-

n = int(input())
for k in range(n+1):
    if k*(k-1) == 2*n:
        break
    elif k*(k-1) > 2*n:
        print('No')
        exit()
print('Yes')
print(k)
ret = [[] for _ in range(k)]
ii = 0
for i in range(k-1):
    for j in range(1,k-i):
        ret[i].append(ii+j)
        ret[i+j].append(ii+j)
    ii += k-i-1
for i in range(k):
    print(' '.join(map(str,[k-1] + ret[i])))
