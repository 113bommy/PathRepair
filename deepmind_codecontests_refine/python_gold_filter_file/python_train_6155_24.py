#coding: utf-8

n = int(input())
x, y = map(int, input().split())

if x - 1 < y - 1:
    w = y - 1
else:
    w = x - 1
    
if n - x < n - y:
    b = n - y
else:
    b = n - x
    
if w > b:
    print('Black')
else:
    print('White')