from collections import deque,namedtuple
P = namedtuple('P',['ff','ss','parent'])
dx = [0,0,-1,1]
dy = [1,-1,0,0]

def found(a,visited,n,m,sx,sy):
    dq,doing = deque(),a[sx][sy]
    dq.append(P(sx,sy,(-1,-1)))
    while len(dq) > 0:
        now = dq.pop()
        visited[now.ff][now.ss] = 1
        for i in range(4):
            tx, ty = dx[i] + now.ff, dy[i] + now.ss
            if not (0 <= tx < n and 0 <= ty < m and a[tx][ty] == doing): continue
            if visited[tx][ty]:
                if not (now.parent[0] == tx and now.parent[1] == ty):
                    return True
            else:
                dq.append(P(tx,ty,(now.ff,now.ss)))



def main():
    n,m = map(int,input().split())
    a = [input() for i in range(n)]
    visited = [ [0 for i in range(m)] for j in range(n)]
    for i in range(n):
        for j in range(m):
            if visited[i][j]: break
            if found(a,visited,n,m,i,j):
                print("Yes")
                exit(0)
    print("No")





if __name__ == "__main__":
    main()