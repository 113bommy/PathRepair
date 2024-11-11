s=input()
n=len(s)+1
l=[0]*n
r=[0]*n
for i in range(n-1):
    if s[i]=='<': 
      l[i+1]=l[i]+1
    if s[n-2-i]=='>': 
      r[n-2-i]=r[n-1-i]+1
ans=0
for i in range(n):
  ans+=max(l[i],r[i])
print(ans)
