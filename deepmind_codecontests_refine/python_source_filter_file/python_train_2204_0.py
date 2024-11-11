t = int(input())
for z in range(t):
    n, m = map(int, input().split())
    arr = [0 for i in range(n)]
    for i in range(n):
        arr[i] = list(input())
    gor = [0 for i in range(n)]
    ver = [0 for i in range(m)]
    for i in range(n):
        for j in range(m):
            if arr[i][j] != '*':
                gor[i] += 1
                ver[j] += 1
    ans = 1000000000000
    for i in range(n):
        for j in range(m):
            ans = min(ans, gor[i] + ver[j] - (1 if arr[i][j] == '#' else 0))
    print(ans)