from collections import deque
h, w = map(int, input().split())
bord = [list(input()) for _ in range(h)]
visit = [[-1 for _ in range(w)] for _ in range(h)]
visit[0][0] = 1


q = deque([[0,0]])
visit[0][0] = 1
while q:
    px, py = q.popleft()
    for i, j in ([1,0],[-1,0],[0,1],[0,-1]):
        if px+i >= 0 and px+i < h and py+j > 0 and py+j < w:
            if bord[px+i][py+j] == "." and visit[px+i][py+j] < 0:
                visit[px+i][py+j] = visit[px][py]+1
                q.append([px+i, py+j])
if visit[h-1][w-1] < 0:
    print(-1)
else:
    c = [i.count(".") for i in bord]
    print(sum(c)-visit[h-1][w-1])