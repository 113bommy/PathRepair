import sys
from sys import stdin

n = int(stdin.readline())
c = list(map(int,stdin.readline().split()))

h = [0]

for i in range(n):
    if i % 2 == 0:
        h.append(h[-1] + c[i])
    else:
        h.append(h[-1] - c[i])

ans = 0
for l in range(0,n,2):

    if l == n-1:
        break

    nmin = float("inf")

    la = h[l]
    lb = h[l+1]

    for r in range(l+1,n,2):
        ra = h[r+1]
        rb = h[r]

        a = max(la,ra)
        b = min(lb,rb,nmin)

        now = max(0 , b-a)
        ans += now

        #print (l,r,now)

        nmin = min(nmin , rb)

print (ans)