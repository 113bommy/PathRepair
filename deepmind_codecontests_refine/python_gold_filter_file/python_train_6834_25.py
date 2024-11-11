#!/usr/bin/python3

n = int(input())
if n >= 37:
    s = -1
elif n % 2 == 0:
    s = "8"* (n//2)
else:
    s = "8"*(n//2) + "6"

print(s)
