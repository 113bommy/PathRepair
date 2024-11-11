import heapq
import sys

class rode():
    def __init__(self,x,y):
        self.x = x
        self.y = y
    def __lt__(self, other):
        return self.y < other.y
    def __gt__(self, other):
        return other > self
    def __le__(self, other):
        return not(other > self)
    def __ge__(self, other):
        return not(self > other)

n,m = map(int,input().split())
da = [[] for i in range(n)]
for i in range(m):
    l,r,c = map(int,input().split())
    da[l-1].append([r-1,c])
for i in range(1,n):
    da[i].append([i-1,0])
pq=[]
ju = [False for i in range(n)]
ju[0] = True
for i in da[0]:
    heapq.heappush(pq, rode(i[0],i[1]))
while(len(pq)):
    now = heapq.heappop(pq)
    if now.x == n-1:
        print(now.y)
        sys.exit()
    if ju[now.x]:
        continue
    ju[now.x] = True
    for i in da[now.x]:
        if ju[i[0]]:
            continue
        heapq.heappush(pq,rode(i[0],now.y+i[1]))
print(-1)
