n=int(input())
k=int(input())
ans=1
for i in range(n):
  ans=max(ans+k,ans*2)
print(ans)
  