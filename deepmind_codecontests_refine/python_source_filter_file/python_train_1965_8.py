#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys

LIMIT = 1000000
is_prime = [True] * (LIMIT+1)
p = 2
while p**2 <= LIMIT:
    if is_prime[p]:
        for i in range(p*2, n+1, p):
            is_prime[i] = False
    p += 1

for line in sys.stdin.readlines():
    n = int(line.strip())
    if n <= 1:
        print(0)
        continue
    if n == 2:
        print(1)
        continue
    num_prime = 1
    for i in range(3, n+1):
        if is_prime[i]:
            num_prime += 1
    print(num_prime)