n,t=map(int,input().split())

r=t+1

for _ in range(n):
  a,b=map(int,input().split())
  if b<=t and a<r:
    r=a
if r==t+1:
  print("TLE")
else:
  print(r)
