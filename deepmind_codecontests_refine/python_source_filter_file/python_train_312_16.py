def chess(h,w):
  if (h+w) % 2 == 0:
    return '#'
  return '.'

while True:
  H, W = map(int, input().split())
  if H == 0 and W == 0:
    break
  for i in range(H):
    for j in range(W):
      print(chess(I,j)', end='')
    print()
  print()

