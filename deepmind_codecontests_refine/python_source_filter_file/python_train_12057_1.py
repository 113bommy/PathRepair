from copy import *
N=int(input())
S=input()
DP=[[[[0]*2 for i in range(2)] for j in range(2)] for k in range(N)]
mod=10**9+7
for i in range(N):
  for j in range(2):
    for k in range(2):
      for l in range(2):
        DP[i][j][k][l]=[[],[],0]
if S[0]=='X':
  DP[0][0][1][0]=[[],[],1]
else:
  DP[0][0][0][1]=[[],[],1]
  DP[0][1][1][1]=[[1],[],mod-1]
g1=[1,1]
g2=[1,1]
inv=[0,1]
c=[1,2]
for i in range(2,N+5):
  g1.append((g1[-1]*i)%mod)
  inv.append((-inv[mod%i]*(mod//i))%mod)
  g2.append((g2[-1]*inv[-1])%mod)
  c.append((c[-1]+g2[i])%mod)

def add(x,y):
  for j in range(2):
    for i in range(len(y[j])-len(x[j])):
      x[j].append(0)
    for i in range(len(y[j])):
      x[j][i]=(x[j][i]+y[j][i])%mod
  x[2]=(x[2]+y[2])%mod

def integrate(p):
  p[2]=-p[2]%mod
  for j in range(2):
    p[j].append(0)
    for i in range(len(p[j])-2,-1,-1):
      p[j][i+1]=p[j][i]*inv[i+1]%mod
      p[j][i]=0

def fx0(p):
  integrate(p)
  p[0][0]=(p[0][0]-p[2])%mod

def f1x(p):
  integrate(p)
  for j in range(2):
    for i in range(len(p[j])):
      p[j][i]=-p[j][i]%mod
  p[2]=-p[2]%mod
  for i in range(2):
    p[i][0]=-sum(p[i])%mod
  p[1][0]=(p[1][0]-p[2])%mod

for i in range(N-1):
  if S[i+1]=='X':
    add(DP[i][1][1][0],DP[i][1][1][1])
    fx0(DP[i][1][1][0])
    add(DP[i][1][1][1],DP[i][1][0][1])
    add(DP[i][1][1][1],DP[i][0][1][1])
    add(DP[i][1][1][1],DP[i][0][0][1])
    f1x(DP[i][1][1][1])
    for j in range(2):
      add(DP[i+1][0][1][0],DP[i][1][1][j])
  else:
    t=[[],[],0]
    add(DP[i][0][1][0],DP[i][0][1][1])
    add(DP[i][1][1][0],DP[i][1][1][1])
    add(DP[i+1][1][1][1],DP[i][0][1][0])
    fx0(DP[i+1][1][1][1])
    add(t,DP[i][0][1][0])
    add(t,DP[i][1][1][0])
    f1x(t)
    fx0(DP[i][1][1][0])
    add(DP[i+1][0][0][1],DP[i][1][1][0])
    add(DP[i+1][0][0][1],t)

def f10(p,o,e):
  r=[0]*3
  q=deepcopy(p)
  integrate(q)
  r[0]=(sum(q[0])-q[2])*o%mod
  r[1]=(sum(q[1])+q[2])*o%mod
  for j in range(2):
    for i in range(len(p[j])):
      r[j]=(r[j]+p[j][i]*g1[i]*e)%mod
      r[j+1]=(r[j+1]-p[j][i]*g1[i]*c[i]*e)%mod
  r[0]=(r[0]+p[2]*inv[2])%mod
  r[2]=(r[2]-p[2]*inv[2])%mod
  return r

add(DP[-1][0][1][1],DP[-1][1][1][1])
add(DP[-1][0][1][0],DP[-1][1][1][0])
add(DP[-1][0][0][1],DP[-1][1][0][1])
X=[f10(DP[-1][0][1][1],1,0),f10(DP[-1][0][1][0],0,1),f10(DP[-1][0][0][1],1,mod-1)]
A=[sum(map(lambda x:x[i],X))%mod for i in range(3)]
print(*A)