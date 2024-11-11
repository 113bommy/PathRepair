H,W = map(int,input().split())
mine_map = [list(input()) for x in range(H)]
for i in range(H):
  for j in range(W):
    count = 0
    if mine_map[i][j] == ".":
      for k in range(-1,2):
        for l in range(-1,2):
          if i+k >= 0 and i+k < H and j+l >= 0 and j+l < W:
            if mine_map[i+k][j+l] == "#":
              count += 1
      mine_map[i][j] = count
    print(mine_map[i][j],end="")
  print()