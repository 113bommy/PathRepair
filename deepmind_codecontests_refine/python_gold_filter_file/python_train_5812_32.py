N,T=list(map(int,input().split()))
ans=1001
for i in range(N):
  c,t=list(map(int,input().split()))
  if T>=t:
    ans=min(ans,c)
print(ans if ans!=1001 else 'TLE')