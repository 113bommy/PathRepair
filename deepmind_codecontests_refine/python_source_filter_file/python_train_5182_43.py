#!/usr/bin python3
# -*- coding: utf-8 -*-

n, k = map(int, input().split())
p = [int(i)-1 for i in input().split()]
c = list(map(int, input().split()))

ret = - 10 ** 18
for s in range(n):
    nxt = p[s]
    S = [c[nxt]]
    while nxt != s:
        nxt = p[nxt]
        S.append(S[-1]+c[nxt])

    if k<=len(S):
        pt = max(S[:k])
    else:
        if S[-1] <= 0:
            pt = max(S)
        else:
            pt = max(S)
            if k%len(S)!=0:
                pt = max(pt, S[-1]+max(S[:k%len(S)]))
            pt += S[-1]*(k//len(S)-1)
    ret = max(ret, pt)
print(ret)