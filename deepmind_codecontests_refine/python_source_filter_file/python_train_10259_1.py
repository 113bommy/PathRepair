#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import time


(A, B, n, x) = (int(i) for i in input().split())

start = time.time()

md  = 1000000007

if A!=1 :
    an  = pow(A, n, md*(A-1))
    bn  = B*(an-1)//(A-1)
    ans = (an*x+bn)%md
else:
    ans = (x+B*(n-1))%md
print(ans)

finish = time.time()
#print(finish - start)
