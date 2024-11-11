n=int(input())
p=list(map(int,input().split()))
m=10**6
ans=1
for i in p:
  if m>i:
    m=i
    ans+=1
  
print(ans)