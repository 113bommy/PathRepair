n,t=map(int,input().split())
c=1001
for _ in range(n):
  a,b=map(int,input().split())
  if b<=t:
    c=min(c,a)
print("TLE" if c==1001 else c)