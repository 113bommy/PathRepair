n=int(input())
f=[list(map(int,input().split())) for i in range(n)]
p=[list(map(int,input().split())) for i in range(n)]
ans=0
for i in range(1,2**10):
  op=[0]*10
  res=0
  for j in range(10):
    if i>>j&1:
      op[j]=1
  for j in range(n):
    cnt=0
    for k in range(10):
      if op[k]&f[j][k]:
        cnt+=1
    res+=p[j][cnt]
  ans=max(ans,res)
print(ans)