N = int(input())
A = list(map(int,input().split(' ')))
ans = set()

for i in range(N-1,-1,-1):
  a = A[i]
  for j in range(i+1,N,i+1):
    if j in ans:
      a += 1
  if a % 2:
    ans.add(i+1)
print(len(ans))
print(*ans)