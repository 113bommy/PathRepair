#!/usr/bin/env python3

import sys

(n, m) = map(int, sys.stdin.readline().split(' '))

a = list(map(int, sys.stdin.readline().split(' ')))

arr = []
s = set()
for i in range(0, n):
    j = n - i - 1
    s.add(a[j])
    arr.append(len(s))

def f(i):
    return str(arr[n - i])

for i in range(m):
    sys.stdout.write(f(int(sys.stdin.readline())) + "\n")
