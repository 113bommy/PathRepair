n = int(input())
A = list(map(int, input().split()))
ans = 10**9
total = sum(A)
acc = 0
for a in A:
  acc += a
  ans = min(ans, abs(total - acc * 2))
print(ans)