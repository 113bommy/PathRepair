s=input()
l=len(s)
ans=10**18
for i in range(l-1):
  if s[i]!=s[i+1]:
    tmp=max(i+1,n-i-1)
    ans=min(ans,tmp)
print(ans)