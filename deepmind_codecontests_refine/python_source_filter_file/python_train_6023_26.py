#!/usr/bin/env python3
#ABC62 C

import math
h,w = map(int,input().split())

def solve(H,W):
    mid = math.floor(W/2)
    ans = float('inf')
    for i in range(1,H):
        Smin = min(i*W,mid*(H-i),(W-mid)*(H-i))
        Smax = max(i*W,mid*(H-i),(W-mid)*(H-i))
        ans = min(ans,Smax-Smin)
    return ans
if h % 3 == 0 or w % 3 == 0:
    print(0)
else:
    print(min(solve(h,w),solve(w,h)))
