N,K=map(int,input().split())
A=sorted(list(map(int,input().split())),reverse=True)
MOD=10**9+7
if N==K:
    ans=1
    for i in A:
        ans=ans*i%MOD
    print(ans)
    exit()
if K==1:
    print(A[0]%MOD)
    exit()
if K%2==1 and A[0]==0:
    print(0)
    exit()
if K%2==1 and A[0]<0:
    ans=1
    for i in range(K):
        ans=ans*A[i]%MOD
    print(ans)
    exit()
if N-A.count(0) <K:
    print(0)
    exit()
if A[-1]>=0:
    ans=1
    for i in range(K):
        ans=ans*A[i]%MOD
    print(ans)
    exit()
l=0
r=N-1
t=[]
c=0
if K%2==1:
    tk=K-1
    flg=True
else:
    tk=K
    flg=False
while c<tk:
    if A[l]*A[l+1]<=A[r]*A[r-1]:
        t.append(A[r])
        t.append(A[r-1])
        r+=2
        c+=2
    else:
        t.append(A[l])
        t.append(A[l+1])
        l+=2
        c+=2
if flg:
    t.append(A[l])
ans=1
for i in t:
    ans=ans*i%MOD
print(ans)