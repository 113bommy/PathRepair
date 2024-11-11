h, w = map(int, input().split())
S = [list(input()) for _ in range(h)]
drc = [[0,1],[0,-1],[1,0],[-1,0]]
for i in range(h):
  for j in range(w):
    if S[i][j] == "#":
      if all([S[i+x][j+y] =="." for x, y in drc if 0 <= i+x < w and 0 <= j+y < h]):
        print("No")
        exit()
print("Yes")