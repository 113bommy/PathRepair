n,t=map(int,input().split())
c=0
for _ in range(n):
  a,b=map(int,input().split())
  if b<=t:
    c=min(c,a)
print("TLE" if c==0 else c)