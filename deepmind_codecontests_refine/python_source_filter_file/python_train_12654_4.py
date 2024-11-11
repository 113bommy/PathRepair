I = lambda: list(map(int, input().split()))
n = int(input())
a = [I() for i in range(n)]
if n==1:
    print(1)
else:
    s = list(map(sum, a))
    x = max(s)-min(s)
    for i in range(n):
        for j in range(n):
            if a[i][j]==0:
                a[i][j] = x
    s = list(map(sum, a))
    s += [sum([a[j][i] for j in range(n)]) for i in range(n)]
    s += [sum([a[i][i] for i in range(n)]), sum([a[i][n-1-i] for i in range(n)])]
    print(x if min(s)==max(s) else -1)