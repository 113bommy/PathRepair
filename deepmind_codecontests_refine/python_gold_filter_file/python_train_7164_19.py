n,m,q=map(int, input().split())

tab=[[0]*(n+1) for _ in range(n+1)]

for _ in range(m):
    l,r=map(int, input().split())
    tab[l][r]+=1

for i in range(1,n+1):
    for j in range(1,n):
        tab[i][j+1]+=tab[i][j]

for _ in range(q):
    p,q=map(int, input().split())
    ans=0
    for i in range(p,q+1):
        ans+=tab[i][q]-tab[i][p-1]
    print(ans)
