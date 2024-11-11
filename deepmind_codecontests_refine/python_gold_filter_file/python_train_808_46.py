n = int(input())
A = list(map(int, input().split()))
ans = 0
for j in range(61):
  ones = 0
  for i in A:
    if i>>j & 1:
      ones += 1
  ans += 2**j*((n-ones)*ones)
print(ans%(10**9+7))