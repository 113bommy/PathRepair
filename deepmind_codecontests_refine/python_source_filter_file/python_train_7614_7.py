[n,m,h] = list(map(int,input().split()))
a = list(map(int,input().split()))
b = list(map(int,input().split()))
ind = [list(map(int, input().split())) for i in range(n)]
for i in range(n):
    row = ind[i]
    ans = m*[0]
    for j in range(m):
        if row[j]>0:
            ans[j] = min(a[j],b[i])
    print(ans)