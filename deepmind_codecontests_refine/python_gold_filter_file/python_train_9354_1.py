H, W = map(int, input().split())
M = [input().split() for _ in range(H)]
for i, r in enumerate(M):
  for j, c in enumerate(r):
    if c == 'snuke':
      print("%s%d" %(chr(ord('A')+j), i+1))
