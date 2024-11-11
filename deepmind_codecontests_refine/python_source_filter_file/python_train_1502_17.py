#!/usr/bin/python3
import sys
input = lambda: sys.stdin.readline().strip()
s = input()
rb = s.count('B')
rs = s.count('S')
rc = s.count('C')
nb, ns, nc = [int(x) for x in input().split()]
pb, ps, pc = [int(x) for x in input().split()]
r = int(input())

def bsearch(L, R, can, left_feasible = True):
    while R - L > 1:
        M = L + (R - L) // 2
        if can(M) ^ left_feasible:
            R = M
        else:
            L = M
    return L if left_feasible else R

print(bsearch(0, 10**12, lambda k: max(k * rb - nb, 0) * pb + max(k * rs - ns, 0) * ps + max(k * rc - nc, 0) * pc <= r))