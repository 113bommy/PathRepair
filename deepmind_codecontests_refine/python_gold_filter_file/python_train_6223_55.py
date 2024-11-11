s=input()
t=input()
n=len(s)
m=len(t)
ans=m
for i in range(n-m+1):
  cnt=0
  for j in range(m):
    if s[i+j]!=t[j]:cnt+=1
  ans=min(ans,cnt)
print(ans)