N,T=map(int, input().split())
ans=10**9
for i in range(N):
  c,t=map(int, input().split())
  if t<=T:
    ans=min(ans,c)
if ans==10**9:
  print("TLE")
else:
  print(ans)