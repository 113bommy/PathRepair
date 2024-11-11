n=int(input())
a=list(map(int,input().split()))
mx=max(a)
d=mx
ans=0
for i in a:
  if abs(i-mx/2)<d:
    d=abs(i-mx/2)
    ans=i
print(mx,ans)

