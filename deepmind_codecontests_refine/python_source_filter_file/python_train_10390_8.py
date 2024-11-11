# -*- coding: utf-8 -*-
"""
Created on Sun Jul 21 23:25:47 2019

@author: Yamazaki Kenichi
"""
import bisect

N, K = map(int,input().split())
A = list(map(int,input().split()))

T = [[] for _ in range(2*10**5+1)]

for i in range(N):
    T[A[i]].append(i)

s = A[0]
pointa = 0
counta, res = 0, [-1]
while True:
    tmp = bisect.bisect_right(T[s], pointa) % len(T[s])
    p_pointa = pointa
    pointa = T[s][tmp] + 1
    if pointa == p_pointa + 1 or pointa < p_pointa:
        counta += 1
        res.append(p_pointa)
    elif pointa == N:
        counta += 1
        res.append(p_pointa)
        break
    s = A[pointa]

ans = []
if K % counta != 0:
    pointa = res[K % counta]
#    ans.append(A[pointa])
    while pointa < N:
        if pointa < T[A[pointa]][-1]:
            tmp = bisect.bisect_right(T[A[pointa]],pointa)
            pointa = T[A[pointa]][tmp] + 1
        else:
            ans.append(A[pointa])
            pointa += 1
#        print(ans)
print(' '.join(map(str,ans)))
