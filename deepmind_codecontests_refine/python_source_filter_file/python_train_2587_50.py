n,s=map(int,input().split())
ans=0
for i in range(n+1):
  for j in range(n+1):
    if s-i-j>-1 and s-i-j<s+1:
      ans+=1
print(ans)