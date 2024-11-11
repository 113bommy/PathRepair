#!/usr/bin/env python

from collections import deque
import itertools as it
import sys
import math

def func():
    N = int(input())

    A = list(map(int, input().split()))
    P = [[(A[0], 0), (0, 0)] for i in range(2 ** N)]

    for i in range(1, 2 ** N):
        Ai = A[i]
        Pi = P[i]
        if (Ai, i) > Pi[0]:
            Pi[1] = Pi[0]
            Pi[0] = (Ai, i)
        elif (Ai, i) > Pi[1]:
            Pi[1] = (Ai, i)
        for j in range(N):
            if (i & (1 << j)) == 0:
                Pindex = P[i + (1 << j)]
                for k in range(2):
                    if Pi[k] > Pindex[0]:
                        Pindex[1] = Pindex[0]
                        Pindex[0] = Pi[k]
                    elif Pi[k] > Pindex[1] and Pi[k] != Pindex[0]:
                        Pindex[1] = Pi[k]
    ans = 0
    for i in range(1, 2 ** N):
        ans = max(ans, P[i][0][0] + P[i][1][0])
        print(ans)
    #print(P)

func()