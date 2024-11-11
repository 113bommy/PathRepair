import sys

input=sys.stdin.buffer.readline

n,m=map(int,input().split())
dress=[input().rstrip() for i in range(n)]

dist=[[min(i,n-1-i,j,m-1-j) for i in range(m)] for j in range(n)]
move=[(1,0),(-1,0),(0,1),(0,-1)]

for i in range(1,n-1):
    for j in range(1,m-1):
        for nx,ny in move:
            if dress[i+nx][j+ny]!=dress[i][j]:
                dist[i][j]=0

for j in range(m):
    for i in range(1,n):
        dist[i][j]=min(dist[i-1][j]+1,dist[i][j])

for j in range(m):
    for i in range(n-2,-1,-1):
        dist[i][j]=min(dist[i+1][j]+1,dist[i][j])

for i in range(n):
    for j in range(1,m):
        dist[i][j]=min(dist[i][j-1]+1,dist[i][j])

ans=n*m
for i in range(n):
    for j in range(m-2,-1,-1):
        dist[i][j]=min(dist[i][j+1]+1,dist[i][j])
        ans+=dist[i][j]

print(ans)
