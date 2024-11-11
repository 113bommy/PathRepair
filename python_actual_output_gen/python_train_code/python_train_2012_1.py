N,T = map(int, input().split())
m = 1001

for i in range(N):
  c,t = map(int,input().split())
  if T >= t: m = min(m,c)
  
if m==1001: print("TLE")
else: print(c)