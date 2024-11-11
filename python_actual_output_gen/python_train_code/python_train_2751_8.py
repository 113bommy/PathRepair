#!/usr/bin/python3
n = int(input())
maxx = 0
maxy = 0
maxarea = 0
for it in list(range(n)):
    inputstr = input().split()
    x = int(inputstr[0])
    y = int(inputstr[1])
    area = 0.5 * x * y
    if(maxarea < area):
        maxarea = area
        maxx = x
        maxy = y
print(maxy + maxx)
