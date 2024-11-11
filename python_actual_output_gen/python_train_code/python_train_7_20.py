#!/usr/bin/env python


t = int(input())
for _ in range(t):
    input()
    lst = list(map(int, input().split()))
    if lst[0] + lst[1] <= lst[-1]:
        print(0, 1, len(lst) - 1)
    else:
        print(-1)
