t = int(input())
for _ in range(t):
    n,m = list(map(int,input().split()))
#    l = list(map(int,input().split()))
    l = []
    for i in range(n):
        x = input()
        x = list(x)
        l.append(x)
    count = 0
    vis = [[False]*m for g in range(n)]
    for i in range(n):
        for j in range( m):
            if j==m-1 and l[i][j]=='R':
                count+=1
            elif l[i][i]=='D' and i==n-1 and j<m-1:
                count+=1
    print(count)