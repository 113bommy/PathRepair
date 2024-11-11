from collections import deque
def main():
    h,w,k = map(int,input().split())
    x,y,gx,gy = map(int,input().split())
    x -= 1
    gx -= 1
    y -= 1
    gy -= 1
    c = [list(input()) for _ in range(h)]
    d = [[-1 for _ in range(w)] for _ in range(h)]
    dx = (1, 0, -1, 0)
    dy = (0, 1, 0, -1)
    que = deque()
    que.append((x,y))
    d[x][y] = 0
    while que:
        (qx,qy) = que.popleft()
        if qx == gx and qy == gy:
            break
        for i in range(4):
            for K in range(1,k+1):
                nx = qx + dx[i]*K
                ny = qy + dy[i]*K
                if not(nx>=0 and h>nx and ny>=0 and w>ny) or c[nx][ny] == '@' or (d[nx][ny] != -1 and d[nx][ny] < d[qx][qy]+1):
                    break
                if d[nx][ny] == -1 or d[nx][ny] > d[qx][qy]+1:
                    d[nx][ny] = d[qx][qy] + 1
                    que.append((nx,ny))
    print(d[gx][gy])
 
 
if __name__ == "__main__":
    main()