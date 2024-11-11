def t(n):
    if n%2==0:
        return(1)
    else:
        return(0)
l=[]
for j in range(3):
    a=list(map(int, input().split()))
    for i in range(3):
        a[i]=a[i]%2
    l.append(a)
#l[i][j] is the i-j th element of matrix
q=[[1,1,1],[1,1,1],[1,1,1]]
for i in range(3):
    for j in range(3):
        if l[i][j]==1:
            q[i][j]=t(q[i][j])
            if i==0:
                q[i+1][j]=t(q[i+1][j])
                if  j==0:
                    q[i][j+1]=t(q[i][j+1])
                elif j==1:
                    q[i][j+1]=t(q[i][j+1])
                    q[i][j-1]=t(q[i][j-1])
                else:
                    q[i][j-1]=t(q[i][j-1])
            elif i==1:
                q[i+1][j]=t(q[i+1][j])
                q[i-1][j]=t(q[i-1][j])
                if  j==0:
                    q[i][j+1]=t(q[i][j+1])
                elif j==1:
                    q[i][j+1]=t(q[i][j+1])
                    q[i][j-1]=t(q[i][j-1])
                else:
                    q[i][j-1]=t(q[i][j-1])
            elif i==2:
                q[i-1][j]=t(q[i-1][j])
                if  j==0:
                    q[i][j+1]=t(q[i][j+1])
                elif j==1:
                    q[i][j+1]=t(q[i][j+1])
                    q[i][j-1]=t(q[i][j-1])
                else:
                    q[i][j-1]=t(q[i][j-1])
for i in range(3):
    for j in  range(3):
        print(q[i][j], end=' ')
    print()