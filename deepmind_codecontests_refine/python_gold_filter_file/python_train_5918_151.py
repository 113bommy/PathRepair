N = int(input())
ans = 0
for i in range(6):
  ans += N % 10
  N //= 10
print(ans)