# -*- coding: utf-8 -*-

import sys
import os

for s in sys.stdin:
    H, W = map(int, s.split())
    if H == W == 0:
        break

    M = []
    for i in range(H):
        s = input().strip()
        M.append(s)

    is_loop = False
    x = 0
    y = 0
    walk = 0
    while True:
        mark = M[y][x]
        walk += 1
        if walk > 150:
            is_loop = True
            break

        if mark == '.':
            break

        if mark == '>':
            x += 1
        elif mark == 'v':
            y += 1
        elif mark == '^':
            y -= 1
        elif mark == '<':
            x -= 1

    if is_loop:
        print('LOOP')
    else:
        print(x, y)