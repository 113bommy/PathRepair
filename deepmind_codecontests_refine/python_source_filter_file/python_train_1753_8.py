k, a, b = map(int, input().split())
if a < k and b >= a:
  print('-1')
elif a >= k:
  print('1')
else:
  ans = k // (a - b) * 2 - 2
  while ans // 2 * a - ans // 2 * b + b < k:
    ans += 2
  print(ans - 1)