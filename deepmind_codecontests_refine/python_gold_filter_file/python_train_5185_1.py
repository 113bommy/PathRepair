N, D = map(int, input().split())
l = [list(map(int, input().split())) for i in range(N)]

ans=0
s=0
for i in range(N):
  for j in range(i+1,N):
    s=0
    for d in range(D):
      s+=(l[i][d]-l[j][d])**2
    if s**(1/2)%1==0:
      ans+=1
print(ans)