#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jun 25 19:16:55 2020

@author: shailesh
"""

a,b = [int(i) for i in input().split()]

#diff = str(b-a)


n_seg = {}

n_seg[0] = 4
n_seg[1] = 2
n_seg[2] = 5
n_seg[3] = 5
n_seg[4] = 4
n_seg[5] = 5
n_seg[6] = 7
n_seg[7] = 3
n_seg[8] = 7
n_seg[9] = 7



tot_sum = 0 



while a<=b:
    n = str(a)
    print(n)
    for i in n:
        tot_sum+=n_seg[int(i)]
    a+=1

print(tot_sum)
    