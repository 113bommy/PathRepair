a,b,c,n=map(int,input().split())
ans=0
for x in range(0,n+1,a):
  for y in range(x,n+1,b):
    if y%c==0:
      ans+=1
print(ans)
