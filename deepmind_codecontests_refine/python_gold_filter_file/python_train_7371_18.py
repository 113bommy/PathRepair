n = int(input())
ans = 1
while (n != 4 and n != 2 and n != 1):
  ans += 1
  if n%2 == 0:
    n = n / 2
  else:
    n = 3 * n + 1

print(ans + 3)