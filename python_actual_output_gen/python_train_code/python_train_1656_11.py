n = int(input())
res = n

for i in range(n):
  cc = 0
  t = i  # 6^pでi円引き出し
  while t > 0:
    cc += t % 6
    t //= 6
  t = n - i  # 9^pで残り引き出し
  while t > 0:
    cc += t % 9
    t //= 9
  if res > cc:
    res = cc
print(res)