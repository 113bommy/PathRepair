#!/usr/bin/env python3
# -*- coding: utf-8 -*-


import time
dic = { '0' : 2, '1' : 7, '2' : 2, '3' : 3, '4' : 3, '5' : 4, '6' : 3, '7' : 5, '8' : 1, '9' : 2}

n = input()
start = time.time()

ans = dic[n[0]]*dic[n[1]]
print(ans)

finish = time.time()
#print(finish - start)
