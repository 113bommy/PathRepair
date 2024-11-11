import sys
input=sys.stdin.readline
k1,k2,k3=map(int,input().split())
n=k1+k2+k3
a1=list(map(int,input().split()))
a2=list(map(int,input().split()))
a3=list(map(int,input().split()))
b=[0]*n
for i in range(k2):
    b[a2[i]-1]=1
for i in range(k3):
    b[a3[i]-1]=2
cntr=[0]*3;cntl=[0]*3
for i in range(n):
    cntr[b[i]]+=1
ans=k1+k2
best_p=0
for i in range(n):
    cntl[b[i]]+=1
    cntr[b[i]]-=1
    best_p=max(best_p,cntl[0]-cntr[1])
    ans=min(ans,cntl[0]+cntl[2]+cntr[0]+cntr[1]-best_p)
print(ans)