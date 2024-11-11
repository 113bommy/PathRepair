#!/usr/bin/env python3
n = int(input())
arr = list(map(int, input().split()))
s = sum(arr)
if s % 2 == 1:
    s -= max(n for n in arr if n % 2 == 1)
print(s)