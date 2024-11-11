#!/usr/bin/env python3

n, m, a = map(int, input().split())
b = sorted(map(int, input().split()))
p = sorted(map(int, input().split()))

left = 1
right = min(n, m)

while left <= right:
    mid = (left + right) // 2
    if a >= sum(max(0, x - y) for x, y in zip(p[:mid], b[-mid:])):
        left = mid + 1
    else:
        right = mid - 1
print(right, max(0, sum(p[:right]) - a))
