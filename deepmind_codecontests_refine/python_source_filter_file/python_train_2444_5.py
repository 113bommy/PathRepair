import sys
def input(): return sys.stdin.readline().strip()
n,m = map(int,input().split())

grid = []
for _ in range(n):
    s = input()
    value = list(s)
    grid.append(value)

# print(grid)


n = len(grid)
m = len(grid[0])

def isvalid(x,y,vis):
    if(x<0 or x>=n or y<0 or y>=m):
        return False
    if(vis[x][y]==0):
        return True
    return False


def checkcycle(x,y,vis,n,m):
    dx = [0,1,0,-1]
    dy = [-1,0,1,0]

    s = [[x,y]]
    pr = grid[x][y]   
    parent = [[[-1,-1] for jj in range(m)]for ii in range(n)]
    while(len(s)>0):
        u=s[-1]

        if(vis[u[0]][u[1]]==0):
            vis[u[0]][u[1]] = 1
            check=0
            checktwo=0
            for i in range(0,4):
                if(isvalid(u[0] + dx[i], u[1] + dy[i],vis) and vis[u[0]+dx[i]][u[1]+dy[i]] == 0 and (pr==grid[u[0] + dx[i]][u[1] + dy[i]])):
                    s.append([u[0] + dx[i],u[1] + dy[i]])
                    check=1
                    parent[u[0]+dx[i]][u[1]+dy[i]] = [u[0],u[1]]
                if(x == dx[i]+u[0]  and y == dy[i]+u[1] and parent[u[0]][u[1]]!=[x,y]):
                    checktwo=1
            if(check==0 and checktwo==1):
                return True
        else:
            s.pop()
            
    return False

f=0
for i in range(n):
    for j in range(m):
        vis = [[0 for jj in range(m)] for ii in range(n)]
        ans = checkcycle(i,j,vis,n,m)
        if(ans):
            f=1
            break
    if(f==1):
        break
# print(ans)
if(f==1):
    print('YES')
else:
    print('NO')