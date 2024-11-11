M = 0
ans = 0
for i in range(5):
  a = append(int(input()))
  b = ((a + 9) // 10) * 10
  M = max(M, b-a)
  ans += b
print(ans - M)