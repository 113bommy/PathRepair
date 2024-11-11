n, p = map(int, input().split())
S = list(map(int, list(input())))

if p == 2 or p == 5:
  ans = 0
  for i, x in enumerate(S[::-1]):
    if x % p == 0:
      ans += n - i
else:
  mods = [0 for _ in range(p)]
  mods[0] = 1

  num = 0
  digit = 1
  for s in S[::-1]:
    num = (s * digit + num) % p
    mods[num] += 1
    digit = (digit * 10) % p
  
  ans = 0
  for m in mods:
    ans += m * (m - 1) // 2

print(ans)
