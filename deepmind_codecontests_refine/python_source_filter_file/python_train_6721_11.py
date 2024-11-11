#!/usr/bin/env python3

num = int(input())
s = input()

a = s.find('>')
b = s.rfind('<')

num = 0

if (a > b or a == -1 or b == -1):
    num = len(s)
if (a < b):
    num = len(s) - (b - a + 1)

print(num)
