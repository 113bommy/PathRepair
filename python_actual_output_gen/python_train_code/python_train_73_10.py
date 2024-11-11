N = int(input())
F = [list(map(int,input().split())) for i in range(N)]
P = [list(map(int,input().split())) for i in range(N)]
 
ans = -10**9
for i in range(2**10-1):
  Bit = [1]**10
  for j in range(10):
    if (i>>j)&1:
      Bit[j]=0
  count = 0
  for k in range(N):
    op = sum(b&f for b,f in zip(Bit,F[k]))
    count+=P[k][op]
  ans = max(ans,count)
 
print(ans)