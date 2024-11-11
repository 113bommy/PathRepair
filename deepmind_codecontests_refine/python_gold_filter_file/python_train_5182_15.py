N,K=map(int,input().split())
P=list(map(int,input().split()))
C=list(map(int,input().split()))
A=[]
S=[]
p=2**N-1
for i in range(N):
  if p>>i&1:
    s=i+1
    tmp=[C[i]]
    while s!=P[i]:
      i=P[i]-1
      tmp.append(C[i])
      p^=1<<i
    A.append(tmp)
    S.append(sum(tmp))
ans=-1*(10**9)-1
for i in range(len(A)):
  a=A[i]
  n=len(a)
  s=S[i]
  for j in range(n):
    t=0
    k=n
    if K>n:
      if s > 0:
        k=K%n
        if k==0:
          k=n
          t=s*(K//n-1)
        else:
          k=K%n
          t=s*(K//n)
    else:
      k=K
    for jj in range(j,k+j):
      if jj>=n:
        jj-=n
      t+=a[jj]
      ans=max(ans,t)
    ans=max(ans,t)
print(ans)