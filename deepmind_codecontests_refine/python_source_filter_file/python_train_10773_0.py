#!/usr/bin/env python
# -*- coding: utf-8 -*-

s = input()
length = len(s)
ans = eval(s)

for j in range(0,length,2):
    if j == 0 or s[j-1] == '*':
        for k in range(j+3,length,2):
            if k == length or s[k] == '*':
                tmp = eval(s[:j] + str(eval(s[j:k])) + s[k:])
                ans = ans if tmp < ans else tmp
print(ans)
