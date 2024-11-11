N,T = map(int,input().split())
cost = 1001
for i in range(N):
  c,t = map(int,input().split())
  if t<=T:cost=min(cost,c)
print("TLE" if cost==1001 else cost)