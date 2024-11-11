import sys 
N = list(map(int, sys.stdin))
bot = N[1]
for i in range(N[0]):
  if bot == 2:
    print(i+1)
    break
  bot == N[bot]
else:
  print(-1)