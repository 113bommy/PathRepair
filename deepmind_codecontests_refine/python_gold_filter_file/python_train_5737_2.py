n=int(input())
L1,L2,R1,R2=-1,-1,1<<30,1<<30

for i in range(1,n+1):
    L,R=map(int,input().split())
    if L>L1:
        L1,L2,indL=L,L1,i
    elif L>L2:
        L2=L
    if R<R1:
        R1,R2,indR=R,R1,i
    elif R<R2:
        R2=R
ans=0
if indL==indR:
    ans=max(ans,R2-L2)
else:
    ans=max(ans,R1-L2,R2-L1)
print(ans)
