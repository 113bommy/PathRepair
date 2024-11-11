# -*- coding: utf-8 -*-

import sys
import os
import math

# input_text_path = __file__.replace('.py', '.txt')
# fd = os.open(input_text_path, os.O_RDONLY)
# os.dup2(fd, sys.stdin.fileno())

n, w = map(int, input().split())
A = list(map(int, input().split()))

pours = [None] * n

B = []
for i, a in enumerate(A):
    B.append((a, i))
B.sort()

#print(B)
for b in B:
    cup = b[0]
    i = b[1]

    pour_amount = math.ceil(cup / 2)
    pours[i] = pour_amount
    w -= pour_amount

if w < 0:
    print(-1)
else:
    for i in range(n-1, -1, -1):
        cup, idx = B[i]
        if cup > pours[i]:
            re_pour_amount = min(w, cup - pours[i])
            pours[i] += re_pour_amount
            w -= re_pour_amount
    print(*pours)