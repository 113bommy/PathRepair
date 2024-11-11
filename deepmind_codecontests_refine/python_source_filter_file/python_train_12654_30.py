def nums(a, n):
    S={sum(a[i][i] for i in range(n)), sum(a[i][n-i-1] for i in range(n))}
    for i in range(n):
        S|={sum(a[i]), sum(a[j][i] for j in range(n))}
    return 1 if S=={0} else max(S)-min(S)
n=int(input())
a=[list(map(int, input().split())) for i in range(n)]
x, y=next((i, j) for i in range(n) for j in range(n) if a[i][j]==0)
a[x][y]=nums(a, n)
print(-1 if nums(a, n)==0 or a[x][y]<=0 else a[x][y])