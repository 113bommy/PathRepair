#!/usr/bin/env python3

import sys

n = int(input())
t = list(set([int(x) for x in input().split()]))

for i in range(0, len(t) - 3):
    if t[i+1] - t[i] == 1 and t[i+2] - t[i+1] == 1:
        print('YES')
        sys.exit(0)
print('NO')
