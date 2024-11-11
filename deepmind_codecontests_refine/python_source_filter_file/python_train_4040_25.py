mport heapq
n,m=map(int,input().split())
list=[[] for i in range(m)]
h=[]
for i in range(n):
  a,b=map(int,input().split())
  if a<=m:
    list[a-1].append(-b)
ans=0
for i in range(m):
  for j in list[i]:
    heapq.heappush(h,j)
  if h:
    ans+=-heapq.heappop(h)
  else:
    continue
print(ans)  