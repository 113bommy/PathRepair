n=int(input())
A=list(map(int,input().split()))
ans=0
for i in range(n):
  for j in range(i):
    ans+=i*j
print(ans)