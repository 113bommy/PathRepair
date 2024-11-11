N, D = map(int,input().split())
K = [list(map(int,input().split()))for x in range(N)]
ans = 0
for i in range(N-1):
  for j in range(i+1,N):
    goukei=0
    for a,b in zip(K[i],K[j]):
      goukei += (a-b)**2
    ans += (goukei**0.5).is_integer()
print(K)