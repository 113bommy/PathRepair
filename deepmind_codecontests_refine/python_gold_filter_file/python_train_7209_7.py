import sys
input = sys.stdin.readline
from bisect import bisect_right as br
t = int(input())
for _ in range(t):
    n,m = map(int,input().split())
    ab = sorted([list(map(int,input().split())) for i in range(m)])
    sa = [0]
    a = [0]
    for i in range(m):
        now = ab[i][0]
        a.append(now)
        sa.append(sa[-1]+now)
    ans = 0
    if n <= m:
        l = m-n+1
    else:
        l = 0
    
    for i in range(m):
        na,nb = ab[i]
        ind = max(l,br(a,nb))
        
        count = sa[-1]-sa[ind-1]
        left = n-(m+1-ind)
        if na < nb and left:
            count += na
            left -= 1
        count += (left)*nb
        ans = max(ans,count)
    print(ans)
    if _ != t-1:
        s = input()