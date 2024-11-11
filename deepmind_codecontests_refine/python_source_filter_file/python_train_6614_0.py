n,m,q=[int(x) for x in input().split()]
L=[]
for i in range(q):
    L.append([int(x)-1 for x in input().split()])
L=L[::-1]
ar=[[1]*m for i in range(n)]
for i in L:
    if i[0] is 2:
        ar[i[1]][i[2]] = i[3]+1
    elif i[0] is 1:
        col = i[1]
        x = ar[n-1][col]
        for j in range(1,n):
            ar[j][col] = ar[j-1][col]
        ar[0][col] = x
    else:
        row = i[1]
        ar[row] = [ar[row][m-1]]+ar[row][:m-1]
for i in ar:
    print(' '.join(map(str, i)))
