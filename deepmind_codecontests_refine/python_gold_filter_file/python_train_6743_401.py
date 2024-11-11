n,x,t=map(int,input().split())
s=n//x * t
if n%x!=0:
  s+=t
print(s)