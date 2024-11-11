#!/usr/bin/env python3
from sys import stdin, stdout

def rint():
    return map(int, stdin.readline().split())
#lines = stdin.readlines()

max_height, max_width = rint()

c = [str()] * max_height
top = max_height
left = max_width
bottom = -1
right = -1
b_exist= 0
for i in range(max_height):
    c[i] = input()
    for j in range(max_width):
        if c[i][j] == 'B':
            b_exist = 1
            if top > i:
                top = i
            if left > j:
                left = j
            if bottom < i:
                bottom = i
            if right < j:
                right = j

if not b_exist:
    print(1)
    exit()
ans = 0
for i in range(top, bottom+1):
    for j in range(left, right+1):
        if c[i][j] == 'W':
            ans +=1

height = bottom - top + 1
width = right - left + 1
diff = height - width
if height > width:
    if diff + width >= max_width:
        ans = -1
    else:
        ans += diff * height
elif height < width:
    if diff + height >= max_height:
        ans = -1
    else:
        ans += diff * width

print(ans)