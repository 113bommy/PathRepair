#!/bin/env python3
n=int(input())
x,y=input().split(' ')
x,y=int(x),int(y)
min_y=y
max_y=y
min_x=x
max_x=x

for x in range(n-1):
    x,y=input().split(' ')
    x,y=int(x),int(y)
    if x>max_x:
        max_x=x
    if x<min_x:
        min_x=x
    if y>max_y:
        max_y=y
    if y<min_y:
        min_y=y

print(max((max_y-min_y),(max_x-min_y))**2)
