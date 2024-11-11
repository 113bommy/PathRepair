t = input()
t = int(t)

for i in range(t):
  a, b= map(int,input().strip().split())
  moves = 0
  if a > b:
    if ((a - b) % 2) == 0:
      moves = 2
    else:
      moves = 1
  elif a < b:
    if ((b - a) % 2) == 0:
      moves = 2
    else:
      moves = 1
  else:
    moves = 0

  print(moves)