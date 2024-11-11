#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import time


n   = int(input())

start = time.time()

ans = 0
for i in range(2, n):
    ans += i*(i+1)

print(ans)
finish = time.time()
print(finish - start)
