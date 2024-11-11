H, W  = map(int, input().split())
grid = [input() for _ in range(H)]
ans = [[0] * W for _ in range(H)]
for i in range(H):
    tmp = 0
    for k in range(W):
        if grid[i][k] == '.':
            tmp += 1
        else:
            ans[i][k] = 0
            for t in range(k-tmp,k):
                ans[i][t] = tmp
            tmp = 0
    for t in range(W-tmp,W):
        ans[i][t] = tmp
a = 0
for i in range(W):
    tmp = 0
    for k in range(H):
        if grid[k][i] == '.':
            tmp += 1
        else:
            for t in range(k-tmp,k):
                a = max(ans[t][i]+tmp-1,a)
            tmp = 0
    for t in range(H-tmp,H):
        a = max(ans[t][i]+tmp-1,a)
print(a)