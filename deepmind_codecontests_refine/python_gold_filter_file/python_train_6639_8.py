n=int(input())
b=list(map(int,input().split()))
ans=0
w=max(b)
a=[0]*(w+1)
for i in b:
  x=i
  while x<=w:
    a[x]+=1
    x+=i
for i in b:
  if a[i]==1:
    ans+=1
print(ans)