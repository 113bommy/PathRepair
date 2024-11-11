n,t=map(int,input().split())

r=2000

for _ in range(n):
  a,b=map(int,input().split())
  if b<=t and a<r:
    r=a
if r==2000:
  print("TLE")
else:
  print(r)
