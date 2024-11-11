H, W, A, B = map(int, input().split())

hbar = H - A
wbar = W - B

s = '0' * B + '1' * wbar
sbar = '1' * B + '0' * wbar
for i in range(A):
  print(s)
for i in range(hbar):
  print(sbar)