n=int(input())
b=[int(i) for i in input().split()]
ans=b[-1]+b[0]
for i,j in zip(b[:-1],b[1:]):
  ans+=min(i,j)
print(ans)
