#!/usr/bin/python3

def readln(): return tuple(map(int, input().split()))

n, m = readln()
if n == 0 and m:
    print('Impossible')
else:
    print(n + m - min(n, m), n + m - (m > 0))
