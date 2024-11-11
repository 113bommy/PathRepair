import sys
input = sys.stdin.readline
for _ in range(int(input())):
  N = int(input())
  a = list(map(int, input().split()))
  table = [0] * 31
  for x in a:
    t = 1
    for i in range(31):
      table[i] += x & t > 0
      t <<= 1
  for i in range(N):
    t = 1
    for j in range(31):
      if a[i] & t:
        if table[j] % 2 == 0: a[i] -= t
      t <<= 1
  
  table = [0] * 31
  for x in a:
    t = 1
    for i in range(31):
      table[i] += x & t > 0
      t <<= 1

  win = 0
  for i in range(30, -1, -1):
    if table[i]:
      if table[i] % 4 == 1: win = 1
      elif N % 2 == 0: win = 1
      else: win = -1
      break
  if win == 1: print("WIN")
  elif win == 0: print("DRAW")
  else: print("LOSE")