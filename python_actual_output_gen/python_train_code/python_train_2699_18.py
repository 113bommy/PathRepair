#!/usr/bin/env python3

n = int(input())

a = [int(x) for x in input().split()]

max = 0
current = 1

for x in range(1, len(a)):
    if a[x] >= a[x-1]:
        current += 1
        if (max < current):
            max = current
    else:
        current = 1
print(max)
