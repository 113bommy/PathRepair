'''n-1 good ones
1 bad one

count for k
    if odd then hop from i=2 swapping neighbors
    if even then hop from i=1 swapping neighbors
non-countable cases should be caught in first line'''
import sys
n,k = map(int,input().split())
if k==n or k==0:
    print(-1)
    sys.exit()
elements = [i+1 for i in range(n)]
i = 1 if (n-k)%2 else 0
while i<n-k:
    elements[i],elements[i+1] = elements[i+1],elements[i]
    i+=2
print(' '.join([str(e) for e in elements]))

