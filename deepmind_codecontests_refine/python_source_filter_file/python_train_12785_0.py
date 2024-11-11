N=int(input().split())
C=[list(map(int,input().split())) for i in range(N)]
C.sort(key=lambda x:sum(x), reverse=True)
ans=0
for i in range(N):
  if i%2==0:
    ans+=C[i][0]
  else:
    ans-=C[i][1]
print(ans)