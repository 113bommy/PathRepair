n=int(input())
l=list(map(int,input().split()))
ans=0

for i in range(0,n,2):
  if l[i]%2!=0:
    ans+=1
print(ans)