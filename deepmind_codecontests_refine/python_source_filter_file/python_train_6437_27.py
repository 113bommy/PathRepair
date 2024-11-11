s=input()
ans=len(s)
for i in range(len(s)-1):
  if s[i]!=s[i+1]:
    ans=min(ans,min(i+1,len(s)-i-1))
print(ans)