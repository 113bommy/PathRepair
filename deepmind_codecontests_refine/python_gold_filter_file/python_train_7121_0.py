#!/usr/bin/env python
n = int(input())
nums = [int(x) for x in input().split()]

fives = 0
zeros = 0

for n in nums:
    if n == 5: 
        fives += 1
    elif n == 0:
        zeros += 1

if (zeros < 1):
    print(-1)
else:
    actfives = (fives // 9) * 9
    if (actfives > 0):
        print('5' * actfives + '0' * zeros)
    else:
        print(0)

