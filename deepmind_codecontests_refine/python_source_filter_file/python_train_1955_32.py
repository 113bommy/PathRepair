n=int(input())
dp=[[0]*19 for _ in range(19)]
ans=0
for _ in range(n):
  a=int(float(input())*10**9)
  f,t=0,0
  while a%2==0:
    t+=1
    a//=2
  while a%5==0:
    f+=1
    a//=5
  t,f=min(t,18),min(f,18)
  ans+=dp[18-t][18-f]
  for i in range(t+1):
    for j in range(f+1):
      dp[i][j]+=1
print(ans)