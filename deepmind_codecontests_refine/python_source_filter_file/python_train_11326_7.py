H, W, A, B = map(int, input().split())

hbar = H - A
wbar = W - B

s = '0' * A + '1' * hbar
sbar = '1' * A + '0' * hbar
for i in range(B):
  print(s)
for i in range(wbar):
  print(sbar)