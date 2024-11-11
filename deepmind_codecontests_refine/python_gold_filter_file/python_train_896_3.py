n, m = map(int, input().split())
vis = [0]*(m+10)
vis[0] = 1
for i in range(n):
    a, b = map(int, input().split())
    if(vis[a] == 1):
        for j in range(a, b+1):
            vis[j] = 1
if(vis[m]):
    print('YES')
else:
    print('NO')
