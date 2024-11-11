N,M=map(int,input().split())
A=list(map(int,input().split()))
A.sort(reverse=True)
B=[0]*(N+1)
for i in range(1,N+1):
    B[i]=B[i-1]+A[i-1]
D=[0]*(2*10**5+1)
for i in range(N):
    D[A[i]]+=1
for i in range(len(D)-1,0,-1):
    D[i-1]+=D[i]
#print(D)
#print(A)
#print(D)
l=-1
r=10**5+1
while r-l>1:
    m=(l+r)//2
    s=0
    for i in range(N):
        s+=D[max(1,m-A[i])]
    if s>=M:
        l=m
    else:
        r=m
ans=0
s=0
for i in range(N):
    v=max(0,r-A[i])
    t=max(0,min(D[v],M-s))
    ans+=B[t]+t*A[i]
    s+=t
ans+=l*(M-s)
print(ans)
