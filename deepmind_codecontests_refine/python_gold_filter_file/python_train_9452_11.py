import sys
sys.setrecursionlimit(10000)

N,M,P=map(int,input().split())
ways=[[] for _ in range(N)]
Rways=[[] for _ in range(N)]

for i in range(M):
  A,B,C=map(int,input().split())
  ways[A-1].append([B-1,C-P])
  Rways[B-1].append(A-1)
  
  
visited=[-float("inf")]*N
visited[0]=0

blacklist=[True]*N
blacklist[-1]=False
"""
for c in range(M):
  for i in range(N):
    if blacklist[i]==True:
      continue
    for to in Rways[i]:
      blacklist[to]=False
"""
def b_update(nord):
  global blacklist
  for to in Rways[nord]:
    if blacklist[to]==True:
      blacklist[to]=False
      b_update(to)
      
b_update(N-1)

for c in range(N):
  flag=False
  for i in range(N):
    debit=visited[i]
    if debit==-float("inf"):
      continue
    for to,cost in ways[i]:
      if visited[to]<debit+cost and not blacklist[to]:
        visited[to]=debit+cost
        flag=True
        
  if not flag:
    break
  if c==N-1:
    print(-1)
    exit()
      
ans=visited[-1]
if ans==-float("inf"):
  print(-1)
else:
  print(max(ans,0))
  
  
