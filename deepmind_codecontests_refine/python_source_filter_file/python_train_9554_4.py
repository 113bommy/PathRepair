H,W,M = map(int,input().split())
P = [0]*(H+1)
Q = [0]*(W+1)
A = []
for k in range(M):
    a,b = map(int,input().split())
    P[a] += 1
    Q[b] += 1
    A.append((a,b))
Pmax = max(P)
Qmax = max(Q)
Pindex = []
Qindex = []
for i in range(H+1):
    if P[i] == Pmax:
        Pindex.append(i)
for i in range(W+1):
    if Q[i] == Qmax:
        Qindex.append(i)
ans = Pmax+Qmax-1
key = 0
for x in Pindex:
  for y in Qindex:
    if (x,y) not in A:
      ans += 1
      key = 1
      break
  if key == 1:
    break
print(ans)
