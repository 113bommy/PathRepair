X, Y = map(int, input().split())

a, b = divmod(2*X-Y, 3)
c, d = divmod(2*Y-X, 3) 
if (not b == d == 0) or (2*a < b) or (2*b < a):
  print(0)
else:
  m, n = 1, 1
  mod = 10**9+7
  for i in range(1, min(a, c)+1):
    m = (m * (a+c-i+1)) % mod
    n = (n * i) % mod
  ans = (m * pow(n, mod-2, mod)) % mod
  print(ans)