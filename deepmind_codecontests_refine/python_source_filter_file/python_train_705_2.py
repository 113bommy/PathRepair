n,m=map(int,input().split())
s=[[]]*m
for i in range(m):
  s[i]=list(map(int,input().split()))
  del s[0]
p=list(map(int,input().split()))

ans=0
for bit in range(1<<n):
  x=0
  for i in range(m):
    y=0
    for j in s[i]:
      if bit&(1<<(j-1)):
        y+=1
    if y%2==p[i]%2:
      x+=1
  if x==m:
    ans+=1

print(ans)