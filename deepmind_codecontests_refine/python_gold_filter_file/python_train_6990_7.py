n,m=map(int,input().split())

a=[list(map(int,input().split())) for _ in range(n)]

res=[1]*n
isPossible=False


for i in range(n):
    cur=0
    res=[1]*n
    for j in range(n):
        if i!=j:
            cur=cur^a[j][0]
    
    for j in range(m):
        if cur^a[i][j]>0:
            res[i]=j+1
            isPossible=True
            break
    if isPossible:
        break

if isPossible:
    print('TAK')
    print(' '.join(map(str,res)))
else:
    print('NIE')