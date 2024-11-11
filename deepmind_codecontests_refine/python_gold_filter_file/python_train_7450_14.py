n, k = map(int, input().split())
sz, ans, step, k = 2 ** n - 1, -1, n, k - 1
while sz > 0:
  if k == (sz - 1) // 2:
    sz = -1
    ans = step
    break
  elif k > (sz - 1) // 2:
    k -= (sz - 1) // 2 + 1
  sz = (sz - 1) // 2
  step -= 1
print(ans if sz == -1 else 1)