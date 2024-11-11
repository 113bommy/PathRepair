import sys
import math
input = sys.stdin.readline
for _ in range(1):
    n,pos,l,r = map(int,input().split())
    if l == 1 and r == n:
        print(0)
        continue

    if l != 1 and r != n:
        ans = min(abs(l-pos),abs(r-pos))+2+abs(r-l)

    else:
        if l == 1:
            ans = abs(pos-r)+1

        else:
            ans = abs(pos-l)+1

    print(ans)