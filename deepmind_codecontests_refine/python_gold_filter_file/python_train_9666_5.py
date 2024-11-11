import sys
input=lambda: sys.stdin.readline().rstrip()
n,m=map(int,input().split())
E=[]
for _ in range(m):
  E.append(tuple(int(i) for i in input().split()))
q=int(input())
Q=[]
for _ in range(q):
  Q.append(tuple(int(i) for i in input().split()))

DP=[[[0]*2 for i in range(n)] for j in range(11)]
for i in range(q):
  v,d,c=Q[i]
  DP[d][v-1][0]=i+1
  DP[d][v-1][1]=c

for d in range(10)[::-1]:
  for v in range(n):
    if DP[d+1][v][0]>DP[d][v][0]:
      DP[d][v]=DP[d+1][v]
  for e in range(m):
    a,b=E[e]
    a-=1
    b-=1
    if DP[d+1][a][0]>DP[d][b][0]:
      DP[d][b]=DP[d+1][a]
    if DP[d+1][b][0]>DP[d][a][0]:
      DP[d][a]=DP[d+1][b]
for i in range(n):
  print(DP[0][i][1])


