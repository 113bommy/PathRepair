from math import ceil
n,t=map(int,input().split());arr=[];ans=0;minn=10**5
for i in range(n):
  a,b=map(int,input().split())
  if t==a:print(i+1);exit()
  if a>t and minn>(a-t):minn=min(ans,a-t);ans=i+1
  elif t>a :
    k=(a-b);n1=ceil((t-k)/b);k1=a+(n1*b)-b
    if minn>abs(t-k1):minn=abs(t-k1);ans=i+1
print(ans)
