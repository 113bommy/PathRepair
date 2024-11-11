n,m,x,y = map(int,input().split())
for i in range(y,0,-1):
    print(x,i)
for i in range(y+1,m+1):
    print(x,i)
level = 0
for i in range(x+1,n+1):
    if level == 0:
        for j in range(m,0,-1):
            print(i,j)
        level=1
    else:
        level=0
        for j in range(1,m+1):
            print(i,j)
    if i==n:
        check = [i,j]
level = 1
if check[1]==1:
    for i in range(x-1,0,-1):
        if level == 0:
            for j in range(m,0,-1):
                print(i,j)
            level=1
        else:
            level=0
            for j in range(1,m+1):
                print(i,j)
else:
    level=0
    for i in range(x-1,0,-1):
        if level == 0:
            for j in range(m,0,-1):
                print(i,j)
            level=1
        else:
            level=0
            for j in range(1,m+1):
                print(i,j)
