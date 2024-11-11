n=int(input())
b=[0]*n
w=[0]*n
for i in range(2*n):
  c,a=input().split()
  if c=="B":b[int(a)-1]=i
  else:w[int(a)-1]=i
bit=[0]*2*n
dp=[(n+1)*[10**10]for _ in range(n+1)]
dp[0][0]=0
for i in range(n+1):
  bitt=bit[:]
  for j in range(n):
    a=0
    k=2*n
    while k:
      a+=bitt[k-1]
      k-=k&-k
    if w[j]!=0:
      k=w[j]
      while k:
        a-=bitt[k-1]
        k-=k&-k
    dp[i][j+1]=min(dp[i][j+1],dp[i][j]+a+w[j]-(i+j))
    k=w[j]+1
    while k<=2*n:
      bitt[k-1]+=1
      k+=k&-k
    if i!=n:
      a=0
      k=2*n
      while k:
        a+=bitt[k-1]
        k-=k&-k
      if b[i]!=0:
        k=b[i]
        while k:
          a-=bitt[k-1]
          k-=k&-k
      dp[i+1][j+1]=dp[i][j+1]+a+b[i]-(i+j+1)
  if i!=n:
    a=b[i]-i
    k=2*n
    while k:
      a+=bit[k-1]
      k-=k&-k
    if b[i]!=0:
      k=b[i]
      while k:
        a-=bit[k-1]
        k-=k&-k
    dp[i+1][0]=dp[i][0]+a
    k=b[i]+1
    while k<=2*n:
      bit[k-1]+=1
      k+=k&-k
print(dp[n][n])