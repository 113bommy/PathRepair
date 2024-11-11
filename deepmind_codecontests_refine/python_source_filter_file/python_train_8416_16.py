n,x=map(int,input().split())
a=list(map(int,input().split()))
eat=0
for i in range(1,n):
  s=a[i-1]+a[i]-x
  if(x>0):
    eat+=min(s,a[i])
    a[i]-=min(s,a[i])
s=a[1]+a[0]-x
eat+=max(s,0)
print(eat)
    
