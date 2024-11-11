n = int(input())
if n % 2:
  print(0)
  quit()
ans = 0
for i in range(36):
  ans += (n // (5 ** i))
print(ans)