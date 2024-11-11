N, X, Y = map(int, input().split())
X,Y = X-1, Y-1

ans = [0] * N
 
for i in range(N-1):
  for j in range(i+1, N):
    d = min(j-i, abs(i-X) + abs(j-Y) + 1)
    ans[d] += 1

print(*ans([1:], sep='\n'))