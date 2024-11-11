N,T=map(int,input().split())
ans=100000000
for i in range(N):
  c,t=map(int,input().split())
  if t>T: continue
  ans=min(c,ans)
print(ans if ans<100000000 else 'TLE')