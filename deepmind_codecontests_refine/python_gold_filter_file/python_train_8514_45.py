s,t=([ord(c)-ord('a') for c in input()]for _ in'xx')
if set(t)-set(s):
  print(-1)
else:
  u=s+s
  nxt = [None for _ in range(len(u)+1)]
  nxt[len(u)]=[0 for _ in range(26)]
  for i in range(len(u)-1,-1,-1):
    nxt[i] = [v+1 for v in nxt[i+1]]
    nxt[i][u[i]]=0
  p = 0
  for c in t:
    p += nxt[p%len(s)][c]+1
  print(p)