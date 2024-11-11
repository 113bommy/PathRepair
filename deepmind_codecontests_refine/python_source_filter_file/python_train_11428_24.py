N, X, M = map(int,input().split())
visited = [(-1,-1)]*M
ans = 0
for i in range(N):
    if visited[X][0] > 0:
        d = ans - visited[X][0]
        left = N-i
        length = i-visited[X][1]
        ans += (left//length)*d
        left %= length
        for j in range(left):
            ans += X
            X = X*X % M
        break
    visited[X] = (ans, i)
    ans += X
    X = X*X % M
print(ans)