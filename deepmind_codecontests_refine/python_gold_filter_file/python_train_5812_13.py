n,t=map(int,input().split())

r=2000+t

for _ in range(n):
  a,b=map(int,input().split())
  if b<=t and a<r:
    r=a
if r==2000+t:
  print("TLE")
else:
  print(r)
