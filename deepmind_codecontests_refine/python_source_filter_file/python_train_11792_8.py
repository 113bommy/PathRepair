import sys
input = sys.stdin.readline
from collections import *

for _ in range(int(input())):
    n, k = map(int, input().split())
    l1, r1 = map(int, input().split())
    l2, r2 = map(int, input().split())
    
    if r1<l2 or r2<l1:
        gap = max(l2-r1, l1-r2)
        ans = 10**18
        
        for i in range(n+1):
            cand = i*gap
            plus1 = (max(r1, r2)-min(l1, l2))*i
            
            if plus1>=k:
                cand += k
            else:
                cand += plus1+(k-plus1)*2
            
            ans = min(ans, cand)
        
        print(ans)
    else:
        inter = min(r1, r2)-max(l1, l2)
        now = n*inter
        plus1 = (max(r1, r2)-min(l1, l2)-inter)*n
        
        if now>=k:
            print(0)
        else:
            if now+plus1>=k:
                print(k-now)
            else:
                print(plus1+(k-now-plus1)*2)