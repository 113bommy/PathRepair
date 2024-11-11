t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    vis = [False for i in range(n)]
    res = []

    for i in range(len(a)):
        if(vis[a[i]-1] == False):
            res.append(a[i])
            vis[a[i]-1] = True
    print(*res)
