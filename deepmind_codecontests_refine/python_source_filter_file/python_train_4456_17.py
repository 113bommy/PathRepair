N=int(input())
XY=[[] for _ in range(N)]
for i in range(N):
  A=int(input())
  for _ in range(A):
    x,y = map(int, input().split())
    x-=1
    XY[i].append([x,y])

ans=0
for bit_state in range(2**N):
  flag=True
  for i in range(N):
    if (bit_state>>i)&1:
      for x, y in XY[i]:
        if (bit_state >>x)&1 != y:
          flag=False
  if flag:
    ans=max(ans, bin(bit_state>>x).count("1"))
    
print(ans) 
