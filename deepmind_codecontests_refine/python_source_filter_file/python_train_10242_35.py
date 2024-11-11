a=[]
for i in range(3):
    b=[int(i) for i in input().split()]
    a.append(b)
c=[[1 for i in range(3)] for i in range(3)]
for i in range(3):
    for j in range(3):
        if a[i][j]%2==1:
            c[i][j]=0 if c[i][j]==1 else 1
            if j!=0:
                c[i][j-1]=0 if c[i][j-1]==1 else 1
            if j!=2:
                c[i][j+1]=0 if c[i][j+1]==1 else 1 
            if i!=0:
                c[i-1][j]=0 if c[i-1][j]==1 else 1
            if i!=2:
                c[i+1][j]=0 if c[i+1][j]==1 else 1
for i in range(3):
    for j in range(3):
        print(c[i][j],end=" ")
    print()