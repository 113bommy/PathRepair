#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2018 pkulkarni <pkulkarni@Praveens-MacBook-Air.local>
#
# Distributed under terms of the MIT license.

def solve(n, k, v):
    if(n >= 30):
        print("YES " + str(n - 1))
        return
    critical = 1
    excess = 0
    while(n > 0):
        # print("Entry: n = ", n, "CRITICAL = ", critical, "Excess = ", excess, "k = ", k)
        if(excess >= k):
            print("YES " + str(n))
            return
        if(critical > k):
            print("NO")
            return
        k -= critical
        n -= 1
        excess += (critical * 2 - 1) * v[n]
        critical = (critical * 2 + 1)
        # print("Exit: n = ", n, "CRITICAL = ", critical, "Excess = ", excess, "k = ", k)
    if(excess >= k):
        print("YES " + str(n))
        return
    print("NO")

v = [0, 1]

for i in range(50):
    a = 1 + 4 * v[-1]
    v.append(a)


t = int(input())

for tcase in range(t):
    inputs = [int(x) for x in input().split()]
    n = inputs[0]
    k = inputs[1]
    solve(n, k, v)





