n,m = map(int, input().split())
a = [[] for i in range(n) ]

for i in range(n):
    a[i] = list(map(int, input().split()))
ans=[]
for i in range(n-1):
    for j in range(m-1):
        if(a[i][j]* a[i+1][j] * a[i][j+1] * a[i+1][j+1] >0):
            a[i][j]=2
            a[i + 1][j]=2
            a[i][j + 1] = 2
            a[i + 1][j + 1] = 2
            ans.append([i,j])

cnt= -1
for i in range(n-1):
    for j in range (m-1 ):
        if a[i][j]==1:
            cnt+=1

if cnt !=-1:
    print(-1)
else:
    print(len(ans))
    for i in ans:
        print(i[0]+1,i[1]+1)
