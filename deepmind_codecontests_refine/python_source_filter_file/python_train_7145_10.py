#!/usr/bin/env python3
# coding=utf-8
import math


n,L = map(int,input().split())
c = list(map(int,input().split()))
for i in range(n-1):
    c[i+1] = min(c[i+1], c[i]*2)
ans = 1e18 + 1
mid = 0
for i in range(n-1,-1,-1):
    need = L >> i
    mid += need * c[i]
    L -= need << i
    ans = min(ans,mid+(L > 0) * c[i])
print(ans)
