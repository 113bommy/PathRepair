#!/usr/bin/env python3
import fractions
import math
import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline

t = int(input())
for i in range(t):
    n = int(input())
    ra, sa, pa = [int(item) for item in input().split()]
    hand = input().rstrip()
    ans = []
    rb = hand.count("R")
    sb = hand.count("S")
    pb = hand.count("P")
    if min(ra, sb) + min(sa, pb) + min(pa, rb) >= math.ceil(n / 2):
        print("Yes")
    else:
        print("No")
        continue
    rr = max(ra - sb, 0)
    rs = max(sa - pb, 0)
    rp = max(pb - rb, 0)
    rest = "R" * rr + "S" * rs + "P" * rp
    itr = 0
    for ch in hand:
        if ch == "R" and pa > 0:
            ans.append("P")
            pa -= 1
        elif ch == "P" and sa > 0:
            ans.append("S")
            sa -= 1
        elif ch == "S" and ra > 0:
            ans.append("R")
            ra -= 1
        else:
            ans.append(rest[itr])
            itr += 1
    print("".join([item for item in ans]))