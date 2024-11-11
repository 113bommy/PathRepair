#!/usr/bin/env python3
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
if n == 1 or m == 1:
    print(0)
    exit()

field = []
for _ in range(n):
    field.append([int(item) for item in input().rstrip()])
if n < m:
    n, m = m, n
    nfield = []
    for col in zip(*field):
        nfield.append(list(col))
    field = nfield[:]
nums = []
for line in field:
    val = 0
    for i, item in enumerate(line):
        val += item << i
    nums.append(val)

if m == 2:
    ans = n * m
    for i in range(2):
        parity = i
        diff = 0
        for j, num in enumerate(nums):
            if parity == 0:
                diff += min(bin(num ^ 3).count("1"), bin(num ^ 0).count("1"))
            else:
                diff += min(bin(num ^ 1).count("1"), bin(num ^ 2).count("1"))
            parity = 1 - parity
        ans = min(ans, diff)
elif m == 3:
    ans = n * m
    # Check 000, 010, 101, 111
    for i in range(2):
        parity = i
        diff = 0 
        for j, num in enumerate(nums):
            if parity == 0:
                c1 = bin(num ^ 5).count("1")
                c2 = bin(num ^ 0).count("1")
                if c1 < c2:
                    diff += c1
                else:
                    diff += c2
            else:
                c1 = bin(num ^ 2).count("1")
                c2 = bin(num ^ 7).count("1")
                if c1 < c2:
                    diff += c1
                else:
                    diff += c2
            parity = 1 - parity
        ans = min(ans, diff)
    for i in range(2):
        parity = i
        diff = 0 
        for j, num in enumerate(nums):
            if parity == 0:
                c1 = bin(num ^ 1).count("1")
                c2 = bin(num ^ 6).count("1")
                if c1 < c2:
                    diff += c1
                else:
                    diff += c2
            else:
                c1 = bin(num ^ 4).count("1")
                c2 = bin(num ^ 3).count("1")
                if c1 < c2:
                    diff += c1
                else:
                    diff += c2
            parity = 1 - parity
        ans = min(ans, diff)
    # Check 001, 011, 100, 110 
    # states = [1, 3, 4, 6]
    # dp = [[n * m] * 4 for _ in range(n+1)]
    # for i in range(4):
    #     dp[0][i] = 0
    # for i, num in enumerate(nums):
    #     for j, frm in enumerate(states):
    #         for k, too in enumerate(states):
    #             if frm == too or frm ^ too == 7:
    #                 continue
    #             dp[i+1][k] = min(dp[i+1][k], dp[i][j] + bin(too ^ num).count("1"))
    # for i in range(4):
    #     ans = min(ans, dp[n][i])
else:
    print(-1)
    exit()

print(ans)

    