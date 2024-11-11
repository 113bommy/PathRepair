N,M = map(int,input().split())

path = [[] for _ in range(N)]
pin = [0]*N
for _ in range(M):
  ip,op = map(int,input().split())
  pin[op-1]+=1
  path[ip-1].append(op-1)

cur = []
for i in range(N):
  if pin[i]==0:
    cur.append(i)

ans = 0
while cur:
  ans += 1
  nxt = []
  for ip in cur:
    for op in path[ip]:
      pin[op] -= 1
      if pin[ip]==0 and not(op in nxt):
        nxt.append(op)
  cur = [x for x in nxt]
print(ans-1)
