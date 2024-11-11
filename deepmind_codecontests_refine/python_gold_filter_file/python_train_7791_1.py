N,M=map(int,input().split())
Q=[[int(i) for i in input().split()] for i in range(M)]
Q.sort(key=lambda x:x[1])
mod=10**9+7
dp=[[[0]*max(1,c) for c in range(max(1,b+1))] for b in range(N+1)]
dp[0][0][0]=1
k=0
for a in range(N+1):
  check=[]
  if k<=M-1:
    while a==Q[k][1]:
      l,r,x=Q[k]
      check.append((l,r,x))
      k+=1
      if k==M:
        break
  for b in range(max(1,a)):
    for c in range(max(1,b)):
      for l,r,x in check:
        if x==1:
          if not b<l:
            dp[a][b][c]=0
            continue
        elif x==2:
          if not (b>=l and c<l):
            dp[a][b][c]=0
            continue
        elif x==3:
          if not c>=l:
            dp[a][b][c]=0
            continue
      dp[a][b][c]%=mod
      if a<=N-1:
        dp[a+1][b][c]+=dp[a][b][c]
        dp[a+1][a][c]+=dp[a][b][c]
        dp[a+1][a][b]+=dp[a][b][c]
ans=0
for b in range(N):
  for c in range(max(1,b)):
    ans+=dp[N][b][c]
    ans%=mod
print(ans)
