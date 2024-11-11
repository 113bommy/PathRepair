def ser(visited,now):
  visited.append(now)
  if len(visited)==n:
    return 1
  cnt=0
  for i in bri[now]:
    if i not in visited:
      cnt+= ser(visited[:],i)
  return cnt

n,m=map(int,input().split())
bri=[[] for _ in range(n)]
for i in range(m):
  a,b=map(int,input().split())
  bri[a-1].append(b-1)
  bri[b-1].append(a-1)
print(ser([],0))