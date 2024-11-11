#!/usr/bin/env python3
import sys
input = sys.stdin.readline

n, k = map(int, input().split())
a = [int(item) for item in input().split()]
if k <= 2:
    print(min(a))
    exit()

l = 0; r = 10**9 + 10
while r - l > 1:
    mid = (l + r) // 2
    is_small = []
    for i, item in enumerate(a):
        if item <= mid:
            is_small.append(1)
        else:
            is_small.append(0)
    if is_small[:3] == [1, 1, 0]:
        is_small[0] = 0
    max_cnt = 0
    for i in range(2):
        cnt = 0
        state = i
        for item in is_small:
            if item:
                if state == 0:
                    cnt += 1
                    state = 1
                else:
                    cnt += 1
                    state = 0
            else:
                if state == 1:
                    cnt += 1
                    state = 0
        max_cnt = max(max_cnt, cnt)
    if max_cnt >= k:
        r = mid
    else:
        l = mid
print(r)