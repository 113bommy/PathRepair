#!/bin/python3

import sys
b = []

for i in range(8):
    b.append(list(input()));
ans1 = 8;
ans2 = 8;
for j in range(8):
    for i in range(8):
        if b[i][j] == 'B':
            break;
        if b[i][j] == 'W':
            ans1 = min(i,ans1)
for j in range(8):
    for i in range(7, -1, -1):
        if b[i][j] == 'W':
            break;
        if b[i][j] == 'B':
            ans2 = min( 8 - i - 1, ans2)
if ans1 <= ans2 :
    print("A")
else:
    print("B")