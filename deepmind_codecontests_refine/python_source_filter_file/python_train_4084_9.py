import sys, math
input = sys.stdin.readline

def getInts():
    return [int(s) for s in input().split()]

def getInt():
    return int(input())

def getStrs():
    return [s for s in input().split()]

def getStr():
    return input().strip()

def listStr():
    return list(input().strip())

import collections as col
import math

"""
this is an alternative O(N) solution (previous solution was O(N log N))
the operation is equivalent to X & (~Y)
"""

def solve():
    N = getInt()
    A = getInts()
    if N == 1:
        print(*A)
        return
    pref = [~A[0]]
    suff = [~A[N-1]]
    for n in range(1,N):
        pref.append(pref[-1]&(~A[n]))
        suff.append(suff[-1]&(~A[n]))
    suff.reverse()
    best = -10**9
    ind = -1
    for n in range(N):
        if n == 0:
            tmp = A[n]&suff[n+1]
        elif n == N-1:
            tmp = A[n]&pref[n-1]
        else:
            tmp = A[n]&pref[n-1]&suff[n+1]
        if tmp > best:
            ind = n
            best = tmp
    if ind == -1:
        print(*A)
    else:
        print(A[ind],*[A[j] for j in range(N) if j != ind])
    return
    
solve()
    

