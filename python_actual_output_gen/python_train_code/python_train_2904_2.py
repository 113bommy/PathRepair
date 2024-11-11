#!/usr/bin/python3

# import sys
# input = sys.stdin.buffer.readline

T = int(input())
for _ in range(1, T + 1):
    d = 1
    n = int(input())
    for i in range(1, 10):
        d += 2**i
        if n % d == 0:
            print(n//d)
            break