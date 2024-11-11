#!/usr/bin/env python
# -*- coding: utf-8 -*-

n = int(input())
c1 = list(map(int,input().split()))[1:]
c2 = list(map(int,input().split()))[1:]

def check(c1,c2):
    t1,t2 = c1.pop(0),c2.pop(0)
    if t1 < t2:
        c2 += [t1,t2]
    else:
        c1 += [t2,t1]

count = 0
while c1 != [] and c2 != []:
    prev_c1,prev_c2 = c1[:],c2[:]
    check(c1,c2)
    if count > 100:
        break
    count += 1
else:
    print(count, 2 if c1 == [] else 1)
    quit()
print(-1)
