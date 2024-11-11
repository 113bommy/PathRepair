n, m, k = map(int, input().split())
a = list(int(x) for x in input().split())
if m == 1:
    a.sort()
    print(sum(a[n-m:n]))
else:
    b = list(sum(a[i:i+m]) for i in range(0, n-m+1))
    c = [[ -1 for j in range(k+1)] for i in range(n+1)]
    for i in range(n+1): c[i][0] = 0
    for i in range(n+1):
        for j in range(1, k+1):
            c[i][j] = c[i-1][j]
            if i - m >= 0 and c[i-m][j-1] != -1:
                c[i][j] = max(c[i][j], c[i-m][j-1] + b[i-m])
    print(c[n][k])
