n,C=map(int,input().split())
stc=[[int(i) for i in input().split()] for _ in range(n)]
dp=[0]*(2*10**5+2)
for j in range(1,C+1):
  tmp=[0]*(2*10**5+2)
  for s,t,c in stc:
    if j == c:
      tmp[2*s-1]+=1
      tmp[2*t]-=1
  for i in range(2*10**5+1):
    tmp[i+1]+=tmp[i]
    dp[i+1]+=tmp[i+1]>0
print(max(dp))
