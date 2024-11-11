import sys
from functools import lru_cache

n=int(input())
a=[int(x) for x in input().split()]

m=a.index(max(a))

if n==1:
    print('B')

    exit()
sys.setrecursionlimit(100000)

@lru_cache(None)
def dp(i):
    if i==m:
        return 0
    else:

        for j  in range(i+a[i],n,a[i]):
            if a[j]>a[i] and  dp(j)==0:
                return 1
        for j in range(i-a[i],-1,-a[i]):
            if a[j]>a[i] and dp(j)==0:
                return 1
        return 0
an=['B','A']
for j in range(len(a)):

    print(an[dp(j)],end='')
print()