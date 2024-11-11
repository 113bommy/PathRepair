a,b,c,n=map(int,input().split())
ans=0
for x in range((n+1)//a):
  for y in range((n+1-a*x)//b):
    z=n-a*x-b*y
    if z>=0 and z%c==0:
      ans+=1
print(ans)
