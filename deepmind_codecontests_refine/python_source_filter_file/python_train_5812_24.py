N,T=map(int,input())
ans=100000000
for i in range(n):
  c,t=map(int,input().split())
  if t>T: continue
  ans=min(c,ans)
print(ans if ans<100000000 else 'TLE')