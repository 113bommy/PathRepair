# -*- coding: utf-8 -*-
# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, A, B, C, D = map(int, input().split())


def check(m):
    return C+(N-1-m)-D*m <= B-A <= -C*m+(N-1-m)*D


for m in range(N):
    if check(m):
        print("YES")
        break
else:
    print("NO")
