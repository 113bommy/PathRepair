from queue import Queue
h,w=map(int,input().split())
S=[list(input()) for _ in range(h)]

memo=[[-1]*w for _ in range(h)]
def bfs(q):
  x,y,cnt=q.get()
  if x<0 or x>=w or y<0 or y>=h:
    return
  elif S[y][x]=='#':
    return
  elif memo[y][x]<0:
    memo[y][x]=cnt
    q.put([x-1,y,cnt+1])
    q.put([x+1,y,cnt+1])
    q.put([x,y-1,cnt+1])
    q.put([x,y+1,cnt+1])

q=Queue()
q.put([0,0,0])
while not q.empty():
  bfs(q)
if memo[y-1][x-1]==-1:
  print(-1)
  exit()
cnt=0
for i in range(h):
  cnt+=S[i].count('.')
print(cnt-memo[h-1][w-1]-1)