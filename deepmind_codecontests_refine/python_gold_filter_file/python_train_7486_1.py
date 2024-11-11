#!/usr/bin/env python
# -*- coding: utf-8 -*-

while True:
    a,L = map(int,input().split(" "))
    if a == 0 and L == 0:
        break
    a_set = dict()
    a_set[a] = 0
    a = str(a)
    a = a + '0' * ( L - len(a))
    i = 1
    while True:
        a = int(''.join(reversed(sorted(a)))) - int(''.join(sorted(a)))
        if a in a_set:
            break
        else:
            a_set[a] = i
        a = str(a)
        a = a + '0' * (L-len(a))
        i += 1
    print(a_set[a],a,i-a_set[a])