N=int(input())

A=[[-1]*N for _ in range(N)]
for i in range(N):
  a=int(input())
  for j in range(a):
    x,y=map(int, input().split())
    A[j][x-1]=y
#正直者が正直者に不親切と言われていない
#→正直ものが不親切を正直者と言っていないか
ans=0
for i in range(2**N):
  ok=True
  for j in range(N):
    if (i>>j&1)==1:
      for k in range(N):
        if A[j][k]!=-1 and (i>>k&1)!=A[j][k]:
          ok=False
  if ok:
    ans=max(ans, bin(i).count("1"))
  
print(ans)