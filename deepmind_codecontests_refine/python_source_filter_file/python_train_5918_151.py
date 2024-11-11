N = int(input())
ans = 0
for i in range(6):
  ans += N % 10
  ans //= 10
print(ans)