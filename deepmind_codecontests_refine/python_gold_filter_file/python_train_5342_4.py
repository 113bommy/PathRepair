N=int(input())
P=list(map(int,input().split()))
x=P.index(1)
Y=[]
for i in range(N*2):
  if x==0:
    break
  if (i^1)&1:
    Y.append(0)
    x^=1
  else:
    Y.append(1)
    if x<N:
      x+=N
    else:
      x-=N
x=P.index(1)
Q=P[:]
Z=[]
if x<N:
  x+=N
else:
  x-=N
Z.append(1)
for i in range(N*2):
  if x==0:
    break
  if (i^1)&1:
    Z.append(0)
    x^=1
  else:
    Z.append(1)
    if x<N:
      x+=N
    else:
      x-=N
for i in range(len(Y)):
  if Y[i]:
    for j in range(N):
      P[j],P[j+N]=P[j+N],P[j]
  else:
    for j in range(0,N<<1,2):
      P[j],P[j+1]=P[j+1],P[j]
ANS=10**9
if sorted(P)==P:
  ANS=min(ANS,len(Y))
for i in range(len(Z)):
  if Z[i]:
    for j in range(N):
      Q[j],Q[j+N]=Q[j+N],Q[j]
  else:
    for j in range(0,N<<1,2):
      Q[j],Q[j+1]=Q[j+1],Q[j]
if sorted(Q)==Q:
  ANS=min(ANS,len(Z))
if ANS==10**9:
  print(-1)
else:
  print(ANS)