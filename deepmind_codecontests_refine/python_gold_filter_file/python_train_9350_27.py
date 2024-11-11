n, k = map(int, input().split())
x = list(map(int, input().split()))

ans = 10**9
for i in range(n-k+1):
  d = x[i+k-1] - x[i] + min(abs(x[i]), abs(x[i+k-1]))
  ans = min(ans, d)
  
print(ans)
