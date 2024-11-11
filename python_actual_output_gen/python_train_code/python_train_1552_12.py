N=int(input())

S=[[-1]*N for _ in range(N)]
for _ in range(N):
  A=int(input())
  for i in range(A):
    x, y=map(int, input().split())
    S[i][x-1]=y
ans=0   
for s in range(2**N):
  ok=True
  for i in range(N):
    #正直者について見ていく
    if (s<<i&1)==1:
      for j in range(N):
        #それぞれ正直者の証言が矛盾ないか
        if S[i][j]!=-1 and (s>>j&1)!=S[i][j]:
          ok=False
  if ok:
    ans=max(ans, bin(s).count("1"))
    
print(ans)
