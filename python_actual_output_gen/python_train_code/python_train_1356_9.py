n=int(input())
k=int(input())
ans=1
for _ in range(n):
  ans=min(ans+k,2*k)
print(ans)