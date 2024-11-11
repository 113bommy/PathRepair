N,T=map(int,input().split())
ans=0
for _ in range(N):
  c,t=map(int,input().split())
  if t<=T:
    ans=max(ans,c)
if ans==0:
  print("TLE")
else:
  print(ans)