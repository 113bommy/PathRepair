
"""

"""

import sys
from sys import stdin

tt = int(stdin.readline())
ANS = []

for loop in range(tt):

    n,m,k = map(int,stdin.readline().split())

    h = list(map(int,stdin.readline().split()))

    nsum = h[0] + m

    ans = "YES"
    for i in range(1,n):
        if nsum < h[i]-k:
            ans = "NO"
            break
        
        nsum += h[i]
        nsum -= max(0,h[i]-k)

    ANS.append(ans)

print ("\n".join(ANS))