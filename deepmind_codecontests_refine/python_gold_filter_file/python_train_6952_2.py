from sys import stdin
import sys
#import numpy as np
import collections
from functools import cmp_to_key
import heapq

##  input functions for me
def rsa(sep = ''):
    if sep == '' :
        return input().split() 
    else: return input().split(sep)
def rip(sep = ''):
    if sep == '' :
        return map(int, input().split()) 
    else: return map(int, input().split(sep))
def ria(sep = ''): 
    return list(rip(sep))
def ri(): return int(input())
def rd(): return float(input())
def rs(): return input()
##
def main():
    S = [rs() for _ in range(3)]
    mi = len(S[0]) + len(S[1]) + len(S[2])
    L = [[set() for i in range(3)] for j in range(3)]
    
    for i in range(3):
        for j in range(3):
            if(i == j): continue
            s = S[i]
            t = S[j]
            for k in range(-len(t), len(s) + 1):
                chk = True
                for l in range(len(s)):
                    ti = l - k
                    if(ti < 0 or ti >= len(t)): continue
                    if(s[l] == t[ti]): continue
                    if(s[l] == '?'): continue
                    if(t[ti] == '?'): continue
                    chk = False
                    break
                if(chk): L[i][j].add(k)
    a = [[0,1,2], [0,2,1], [1,0,2], [1,2,0], [2,0,1], [2,1,0]]
    for ord in a:
        i = ord[0]
        j = ord[1]
        k = ord[2]
        la = 0
        ra = len(S[i])
        for ij in L[i][j]:
            lb = ij
            rb = ij + len(S[j])
            for ik in L[i][k]:
                lc = ik
                rc = ik + len(S[k])
                if lb <= lc and lc < rb:
                    if not ((lc - lb) in L[j][k]): continue
                if lc <= lb and lb < rc:
                    if not ((lb - lc) in L[k][j]): continue
                l = min(la, lb)
                l = min(l, lc)
                r = max(ra, rb)
                r = max(r, rc)
                mi = min(mi, r - l)
    
    print(mi)
                


if __name__ == "__main__":
    main()
