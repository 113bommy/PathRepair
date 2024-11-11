#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

(n, m, d) = map(int, input().split())
nums = list(map(int, input().split()))

sum_ = sum(nums)

if (m+1) * (d-1) + sum_ < n:
    print("NO")
else:
    print("YES")
    ans = []
    need_jump = n - sum_
    index = 1
    while need_jump:
        jump = min(need_jump, d - 1)
        ans += jump * [0]
        if index <= m:
            ans += [index] * nums[index - 1]
            index += 1
        need_jump -= jump
    while index <= m:
        ans += [index] * nums[index - 1]
        index += 1

    print(" ".join(map(str, ans)))
        

