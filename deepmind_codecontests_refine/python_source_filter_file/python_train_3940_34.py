N = int(input())
K = int(input())
ans = 1
for i in range(N):
  ans += min(K, ans*2)
print(ans)