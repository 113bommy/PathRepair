n = int(input())
a = list(map(int, input().split()))
ans=0
for i in range(60):
  g = [0,0]
  for j in a:
    g[(j>>i)%2]+=1
  ans+=2**i*g[0]*g[1]
  ans%=10**9+7
print(ans)