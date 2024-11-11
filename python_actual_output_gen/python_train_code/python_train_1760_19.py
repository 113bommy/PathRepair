n=int(input())
a=[0]+list(map(int,input().split()))
ans=0
for i in range(1,n+1):
  if a[a[i]]==i:
    ans+=1
print(ans)