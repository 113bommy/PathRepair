t = int(input())

for _ in range(t):
  n, a, b, c, d = map(int, input().split())
  
  memo = {}
  def f(n):
    if n == 0:
      return 0
    if n == 1:
      return d
    if n in memo:
      return memo[n]

    m2 = n % 2
    m3 = n % 3
    m5 = n % 5 
    ret = min(
      d * n,
      d * m2 + a + f((n - m2) // 2),
      d * m2 + a + f((n + m2) // 2),
      d * m3 + b + f((n - m3) // 3),
      d * (3 - m3) + b + f((n + 3 - m3) // 3),
      d * m5 + c + f((n - m5) // 5),
      d * (3 - m3) + c + f((n + 5 - m5) // 5),
    )
    memo[n] = ret
    return ret
  print(f(n))