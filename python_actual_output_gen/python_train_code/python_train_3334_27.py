s=input()
n=len(s)+1
l=[0]*n
r=[0]*n
for i in range(n-1):
    if S[i]=='<': 
      l[i+1]=l[i]+1
    if S[n-2-i]=='>': 
      r[n-2-i]=r[n-1-i]+1
ans=0
for i in range(N):
  ans+=max(l[i],r[i])
print(ans)
