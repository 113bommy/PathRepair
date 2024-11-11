import sys
input = sys.stdin.readline
n,m,p = map(int,input().split())
abd = [list(map(int,input().split())) for i in range(m)]
come = [[] for i in range(n+1)]
for a,b,d in abd:
  come[b].append(a)
visitable = [0]*(n+1)
stack = [n]
visitable[n] = 1
while stack:
  x = stack.pop()
  for y in come[x]:
    if visitable[y] == 0:
      visitable[y] = 1
      stack.append(y)
score = [10**15 for i in range(n+1)]
score[1] = 0
for j in range(n+1):
  flg = 0
  for i in range(m):
    v1,v2,e = abd[i]
    if visitable[v1] & visitable[v2] == 0:
      continue 
    e = -e+p
    if score[v1] != 10**15 and score[v2] > score[v1]+e:
      score[v2] = score[v1]+e
      flg = 1
      if j == n-1:
        last = score[:]
      if j == n:
        onemore = score[:]
  if flg == 0:
    break
if flg == 0:
  print(max(0,-score[n]))
else:
  if last == onemore:
    print(max(last[n],0))
  else:
    print(-1)