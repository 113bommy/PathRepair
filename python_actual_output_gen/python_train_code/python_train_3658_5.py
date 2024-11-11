#!/usr/bin/pypy3
import sys
# sys.stdin = open("/home/vaibhav/python/input.txt", "r")
# sys.stdout = open("/home/vaibhav/python/output.txt", "w")
n = int(input())
mini = 0
maxi = 0
mn = sys.maxsize
mx = 0
for i in range(1, n):
    x, y = map(int, input().split())
    if (x <= mn) and (y >= mx):
        mn = x
        mini = i
        mx = y
        maxi = i
    if y > mx:
        mx = y
        maxi = i
    if x < mn:
        mn = x
        mini = i
if mini == maxi:
    print(mini)
else:
    print(-1)
