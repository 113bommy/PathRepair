input()
p = list(map(int, input().split()))
for i, p_ in enumerate(p):
  a += (p_ != (i + 1))
print('YNEOS'[a > 2 :: 2])
