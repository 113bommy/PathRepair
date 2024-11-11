n=int(input())
ans=0
for i in range(n):
  l,s=map(int,input().split())
  ans+=s-l+1
print(ans)