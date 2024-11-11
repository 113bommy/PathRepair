from collections import deque
import sys
ans = 0
input = sys.stdin.readline
n = int(input())

def put():
    return map(int, input().split())

def bfs(l):
    dis = [0]*n
    for i in l:
        dis[i]=1
        q.append(i)
    i = -1
    while q:
        i = q.popleft()
        for j in tree[i]:
            if dis[j]==0:
                parent[j]=i
                q.append(j)
                dis[j]=dis[i]+1
    return i,dis[i]


parent = [-1]*n
tree = [[] for _ in range(n)]
for _ in range(n-1):
    x,y = put()
    tree[x-1].append(y-1)
    tree[y-1].append(x-1)

q = deque()
far, _ = bfs([0])

end, dis = bfs([far])

parent[far]=-1
curr = end
l = []
while curr!=-1:
    l.append(curr)
    curr = parent[curr]
third, dis2 = bfs(l)


if third in [far, end]:
    x=0
    while x not in [far, end]:
        x+=1
    third = x


print(dis+dis2-2)
print(far+1, end+1, third+1)
