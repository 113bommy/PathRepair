q=int(input())
while q:
    q-=1
    n=int(input())
    a=[]
    for i in range(n):
        a.append(list(map(int,list(input()))))
    g=1
    for i in range(0,n):
        for j in range(0,n):
            if a[i][j]==1:
                if i==n-1 or j==n-1:
                    continue
                if a[i][j+1]==1:
                    continue
                if a[i+1][j]==1:
                    continue
                g=0
    if g:
        print("YES")
    else:
        print("NO")