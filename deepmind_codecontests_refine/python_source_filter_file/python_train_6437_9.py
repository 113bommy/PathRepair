s=input()
n=len(s)
ans=n
for i in range(n-1):
  if s[i+1]!=s[i]:   
    ans=min(ans,max(i,n-i-1))
print(ans)