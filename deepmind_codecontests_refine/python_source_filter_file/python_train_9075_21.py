#!/usr/bin/python3

def readln(): return tuple(map(int, input().split()))

s = list(input())
a = [1 for _ in s if _ == '4']
b = [1 for _ in s if _ == '7']
if a >= b:
    print(4)
elif b > a:
    print(7)
else:
    print(-1)
