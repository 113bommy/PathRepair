N = int(input())
A = [input() for i in range(N)]
ans = 0
for i in range(N):
  ans += len(set(A[0][i],A[1][i],A[2][i]))-1
print(ans)