#!/usr/bin/python3
import sys
input = lambda: sys.stdin.readline().strip()
for _ in range(int(input())):
    n, k = [int(x) for x in input().split()]
    a = sorted(int(x) for x in input().split())
    print(sum(a[:-(k+1)]))