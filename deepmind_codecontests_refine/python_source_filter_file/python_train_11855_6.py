n,m=map(int,input().split())
a=[1]*n
ans=set([1])
for i in range(m):
  x,y=map(int,input().split())
  if a[x-1]==0:continue
  else:
    a[x-1]-=1
    a[y-1]+=1
    if x in ans:
      ans.add(y)
      if a[x-1]==0:ans.rempve(x)
print(len(ans))