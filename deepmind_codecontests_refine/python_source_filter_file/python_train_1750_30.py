H, W, N, sr, sc, S, T = open('0').read().split()
H, W, N, sr, sc = map(int, (H,W,N,sr,sc))
dpr = [0]*(N+1)
dpl = [0]*(N+1)
dpu = [0]*(N+1)
dpd = [0]*(N+1)
dpr[0] = W-sc
dpl[0] = sc-1
dpu[0] = sr-1
dpd[0] = H-sr
for i in range(N):
  if S[i]=='R':
    dpr[i] -= 1
    if 0>dpr[i]:
      print('NO')
      break
  elif S[i]=='D':
    dpd[i] -= 1
    if 0>dpd[i]:
      print('NO')
      break
  elif S[i]=='L':
    dpl[i] -= 1
    if 0>dpl[i]:
      print('NO')
      break
  else:
    dpu[i] -= 1
    if 0>dpu[i]:
      print('NO')
      break
  if T[i]=='R':
    dpl[i+1] = min(W-1,dpl[i]+1)
    dpr[i+1] = dpr[i]
    dpd[i+1] = dpd[i]
    dpu[i+1] = dpu[i]
  elif T[i]=='L':
    dpr[i+1] = min(W-1,dpr[i]+1)
    dpl[i+1] = dpl[i]
    dpu[i+1] = dpu[i]
    dpd[i+1] = dpd[i]
  elif T[i]=='U':
    dpd[i+1] = min(H-1,dpd[i]+1)
    dpl[i+1]= dpl[i]
    dpu[i+1] = dpu[i]
    dpr[i+1] = dpr[i]
  else:
    dpu[i+1] = min(H-1,dpu[i]+1)
    dpl[i+1] = dpl[i]
    dpr[i+1] = dpr[i]
    dpd[i+1] = dpd[i]
else:
  print('YES')