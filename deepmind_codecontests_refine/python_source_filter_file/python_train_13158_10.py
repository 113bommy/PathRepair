from sys import stdin,stdout
from itertools import accumulate
nmbr=lambda:int(stdin.readline())
lst = lambda: list(map(int,stdin.readline().split()))
for _ in range(1):#nmbr()):
    n,k=lst()
    a=lst()
    NI=float('-inf')
    ps=list(accumulate(a))
    lr=[0]*n
    for i in range(k-1,n):
        lr[i]=ps[i]-(ps[i-k] if i-k>=0 else 0)
    # print(lr)
    dp=[[0 for i in range(2)] for _ in range(n+1)]
    for i in range(1,n+1):
        dp[i][0]=max(dp[i-1][0],lr[i-1])
        dp[i][1]=max(dp[i-1][1],lr[i-1]+(dp[i-k][0] if i-k>1 else NI))
    # print(dp)
    y=n
    ansx=ansy=0
    while y>0:
        if dp[y][1]==dp[y-1][1]:
            y-=1
        else:
            ansy=y
            break
    x=ansy-k
    while x>0:
        if dp[x][0]==dp[x-1][0]:x-=1
        else:
            ansx=x
            break
    print(ansx-k+1,ansy-k+1)