#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import time

(n, r) = (int(i) for i in input().split())
c      = [int(i) for i in input().split()]

start = time.time()

s  = sum(c)
n2 = 2**n

ans = [s/n2]
for i in range(r):
    (k, new) = (int(i) for i in input().split())
    s       += new - c[k]
    c[k]     = new
    ans.append(s/n2)

for i in range(len(ans)):
    print(ans[i])

finish = time.time()
#print(finish - start)
