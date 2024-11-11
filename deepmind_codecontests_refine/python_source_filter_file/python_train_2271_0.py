import sys
input = sys.stdin.readline

N=int(input())
B=sorted([list(map(int,input().split())) for i in range(N)],key=lambda x:x[0]+x[1])
#W+Sの順にソートすると無駄がない。

DP=[0]*(10**4+2)
#重さの合計がWのときの価値。
#W=10**4+1ならそれ以上更新されないので、W>=10**4+1以上のものはそこに置く

for w,s,v in B:
    
    if 10**4+1-w<=s:
        x=max(DP[10**4+1-w:s+1])+v
        if DP[-1]<x:
            DP[-1]=x
        
    for i in range(min(10**4-w,s),-1,-1):
        if DP[i+w]<DP[i]+v:
            DP[i+w]=DP[i]+v

print(max(DP))