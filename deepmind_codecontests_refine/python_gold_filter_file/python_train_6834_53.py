#!/usr/bin/env python

innum = int(input())

if innum > 36:
    ans = '-1'
elif innum % 2 == 0:
    ans = '8' * (innum // 2)
else:
    ans = '8' * (innum // 2) + '4'

print(ans)
