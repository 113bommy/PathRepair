N,S,Q,*k = open(0).read().split()
N,Q = map(int, (N,Q))
K = map(int, k)
for k in K:
  D = 0
  M = 0
  DM = 0
  DMC = 0
  for i in range(k):
    if S[i]=='D':
      D += 1
    elif S[i]=='M':
      DM += D
      M += 1
    elif S[i]=='C':
      DMC += DM
  for i in range(N-k):
    if S[i]=='D':
      DM -= M
      D -= 1
    elif S[i]=='M':
      M -= 1
    if S[i+k]=='D':
      D += 1
    elif S[i+k]=='M':
      DM += D
      M += 1
    elif S[i+k]=='C':
      DMC += DM
  print(DMC)
