n,m=map(int,input().split())
k=[0]*m
s=[[]for _ in range(m)]
for i in range(m):
  k[i], *s[i] = map(int, input().split())
p=list(map(int,input().split()))
ans=0
for i in range(2**n):
  res=0
  for a in range(m):
    tmp=p[a]
    for j in s[a]:
      if (i >> (j-1)) & 1:
        tmp^=1
    res+=tmp
  if res==m:
    ans+=1
print(ans)