N=int(input())
S=input()
Sf=S[:N]
Sb=S[N:2*N]
Sb=Sb[::-1]
ans=0
for i in range(2**N):
  R=[]
  B=[]
  for k in range(N):
    if i&(1<<k):
      R.append(Sf[k])
    else:
      B.append(Sf[k])
  dp=[[0]*(N+1) for i in range(N+1)]
  dp[0][0]=1
  f=True
  for k in range(1,N+1):
    for j in range(N):
      if j<len(R):
        if Sb[k-1]==R[j]:
          dp[k][j+1]+=dp[k-1][j]
      if 0<=k-j-1<len(B):
        if Sb[k-1]==B[k-j-1]:
          dp[k][j]+=dp[k-1][j]
  ans+=sum(dp[N])
print(ans)
   
      
    