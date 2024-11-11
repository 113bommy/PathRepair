#!/bin/python3
n,m = map(int, input().split())

if m and not n:
    print("Impossible")
    exit()

print(n + max(0, m-n), n + max(0, m - 1))