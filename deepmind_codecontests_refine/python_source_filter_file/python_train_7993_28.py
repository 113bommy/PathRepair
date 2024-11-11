i, j = map(int, input().split())

if (i + j) % 3 != 0 or (max(i, j) / min(i, j) >= 2):
  print(0)
else:
  TW = (i + j) // 3
  W = (TW - (i-j)) // 2

  def mod_cmb(n, r, mod=10**9+7):
      r = min(r, n-r)
      res = 1
      for i in range(r):
          res = res * (n - i) % mod * pow(i+1, mod-2, mod) % mod
      return res

  print(mod_cmb(TW, W))