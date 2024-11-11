H, W = map(int, input().split())
for h in range(0, H+1):
  for w in range(0, W+1):
    if h*W + w*H - h*w == K:
      print('Yes')
      exit()
print('No')