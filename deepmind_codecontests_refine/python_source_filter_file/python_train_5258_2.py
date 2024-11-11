#!/usr/bin/env python
# -*- coding: utf-8 -*-

n,t = map(int,input().split())
s1 = list(input())
s2 = list(input())
lowercase = set([chr(i) for i in range(ord('a'), ord('z')+1)]) 

ans = [False for i in range(n)]
count = 0

for i in range(n):
    if s1[i] != s2[i]:
        count += 1
    else:
        ans[i] = s1[i]

if count > t and (n - count) < (count-t) * 2:
    print(-1)
else:
    for i in range(n):
        if count > t and not ans[i]:
            ans[i] = s1[i]
            for j in range(i,n):
                if not ans[j]:
                    ans[j] = s2[j]
                    break
            count -= 1
        elif count < t and ans[i] is not False:
            ans[i] = (lowercase - set(s1[i]) - set(s2[i])).pop()
            count += 1
        elif not ans[i]:
            ans[i] = (lowercase - set(s1[i]) - set(s2[i])).pop()
    print(''.join(ans))
