N,T=map(int, input().split())
R=[999999999]
for i in range(N):
  c,t=map(int, input().split())
  if T>t:
    R.append(c)
    
print('TLE' if len(R)==1 else min(R))