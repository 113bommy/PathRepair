import sys
import math
from collections import defaultdict
n=int(sys.stdin.readline())
s=list(sys.stdin.readline()[:-1])
count=0
ans=n*(n-1)//2
for x in range(2):
    count=1
    for i in range(1,n):
        if s[i]==s[i-1]:
            count+=1
        else:
            ans-=(count-x)
            count=1
    s=s[::-1]
print(ans)
