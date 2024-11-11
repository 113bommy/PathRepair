n,c=map(int,input().split())
x=0
a=list(map(int,input().split()))
if(len(a)>0):
  x=1
for i in range(1,n):
  if(a[i]-a[i-1]<=c):
    x+=1
  else:
    x=0
print(x)