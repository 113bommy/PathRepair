import sys
import math
t = int(input())

for i in range(t):
    n = int(input())
    a = input().split(" ")
    a = [int(aa) for aa in a]
    maxdp = [0]*n
    for i in range(n,0,-1):
        maxc = 1
        k = 2*i
        while(k<=n):
            if a[k-1] > a[i-1]:
                maxc = max(maxc, maxdp[k-1] + 1)
            k = k + i
        maxdp[i-1] = maxc
    print(maxdp[0])