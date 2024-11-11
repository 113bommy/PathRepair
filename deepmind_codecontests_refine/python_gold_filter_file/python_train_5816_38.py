xs,ys,xt,yt = map(int,input().split())
N = int(input())
XYR = [list(map(int,input().split())) for _ in [0]*N]
XYR.append([xs,ys,0])
XYR.append([xt,yt,0])

E = [{} for _ in [0]*(N+2)]
for i in range(N+2):
    for j in range(N+2):
        if j==i : continue
        dx = XYR[i][0]-XYR[j][0]
        dy = XYR[i][1]-XYR[j][1]
        r2 = XYR[i][2]+XYR[j][2]
        E[i][j] = max(0,(dx**2+dy**2)**0.5 - r2)

import heapq
def Dijkstra(N,E,start):
    d = [-1]*N
    q = [(0,start)]
    while q:
        ci,i = heapq.heappop(q)
        if d[i]!= -1:continue
        d[i] = ci
        for j,cj in E[i].items():
            if d[j]!=-1:continue
            heapq.heappush(q,(ci+cj,j))
    return d

print(Dijkstra(N+2,E,N)[-1])