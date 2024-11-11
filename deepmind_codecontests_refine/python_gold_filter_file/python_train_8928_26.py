def ii():return int(input())
def iim():return map(int,input().split())
def iil():return list(map(int,input().split()))
from collections import deque


def bfs(xg,yg):
    queue = deque([(xs,ys,0)])
    while queue:
        x,y,dep = queue.popleft()
        l = []
        for xx,yy in [(1,0),(0,1),(-1,0),(0,-1)]:
            for i in range(1,k+1):
                nx,ny = x+xx*i,y+yy*i
                if cord[ny][nx] == '.':
                    l.append((nx,ny))
                elif type(cord[ny][nx]) != int or cord[ny][nx] < dep+1:
                    break
        for nx, ny in l:
            if cord[ny][nx] == '.':
                cord[ny][nx] = dep+1
                if (nx,ny) == (xg,yg):
                    return dep+1
                else:
                    queue.append((nx,ny,dep+1))
    return -1

h,w,k = iim()
ys,xs,yg,xg = iim()

cord = [['@']*(w+2)]
for i in range(h):
    cord.append(['@']+list(input())+['@'])
cord.append(['@']*(w+2))
cord[ys][xs] = '#'

print(bfs(xg,yg))
