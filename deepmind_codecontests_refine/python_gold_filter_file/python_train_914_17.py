n=int(input())
a=map(int,input().split())
minn=0
ans=0
for i in a:
  if i>=minn:
    ans+=1
    minn=i
print(ans)
