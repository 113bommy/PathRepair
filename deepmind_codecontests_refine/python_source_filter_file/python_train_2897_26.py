n=int(input())
s=[input() for _ in range(n)]
ans=0
for k in range(n):
  cnt=0
  for i in range(n):
    l=(i+k)%n
    for j in range(n):
      cnt+=s[i][j]==s[(i+l-j)%n][l]
  if cnt==n**2:ans+=n
print(ans)