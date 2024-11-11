H,W=map(int,input().split())
S = [ input() for _ in range(H) ]
for h in range(H):
  L = ''
  for w in range(W):
    if S[h][w] == '#':
      L += '#'
    else:
      x = 0
      for dh in [ -1, 0, 1]:
        for dw in [-1, 0, 1]:
          if 0 <= h + dh < H and 0 <= w + dw < W and S[h+dh][w+dw] == '#':
            x += 1
      L += str(x)
  print(l)
