#!/usr/bin python3
# -*- coding: utf-8 -*-

a, b = map(int, input().split())
retBW = [['#']*100 for i in range(50)]
retWB = [['.']*100 for i in range(50)]
for i in range(0, 50, 2):
    for j in range(0, 100, 2):
        if a>1:
            retBW[i][j]='.'
            a -= 1

for i in range(1, 50, 2):
    for j in range(0, 100, 2):
        if b>1:
            retWB[i][j]='.'
            b -= 1

print('100 100')
for x in retBW:
    print(''.join(x))
for x in retWB:
    print(''.join(x))
