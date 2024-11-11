#import sys
#input=sys.stdin.readline
from collections import Counter
n=int(input())
A=tuple(input().split())
C=Counter(A)
c1,c2,c3=[C[s] for s in ('1','2','3')]
DP=[[[0]*(n+1) for _ in range(n+1)] for _ in range(n+1)]
for i in range(c3+1):
    for j in range(c3+c2-i+1):
        for k in range(n-i-j+1):
            if i==j==k==0:
                continue
            tmp=n
            if i>0:
                tmp+=DP[k][j+1][i-1]*i
            if j>0:
                tmp+=DP[k+1][j-1][i]*j
            if k>0:
                tmp+=DP[k-1][j][i]*k
            DP[k][j][i]=tmp/(i+j+k)
print(DP[c1][c2][c3])