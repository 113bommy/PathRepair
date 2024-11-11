while 1:
    M = int(input())
    N = int(input())
    if M == N == 0:
        break
    S = [list(map(int, input().split())) for i in range(N)]
    used=[[0]*M for i in range(N)]
    def dfs(x, y, dd=((-1,0),(0,-1),(1,0),(0,1))):
        r = 0
        for dx, dy in dd:
            nx = x + dx; ny = y + dy
            if 0 <= nx < M and 0 <= ny < N and S[ny][nx] and not used[ny][nx]:
                used[ny][nx] = 1
                r = max(r, dfs(nx, ny)+1)
                used[ny][nx] = 0
        return r
    ans = 0
    for i in range(N):
        for j in range(M):
            if S[i][j]:
                used[i][j] = 1
                ans = max(ans, dfs(i, j)+1)
                used[i][j] = 0
    print(ans)
