while True:
  H, W = map(int, input().split())
  if H == W == 0: break
  print(('#' * H + '/n') * W)