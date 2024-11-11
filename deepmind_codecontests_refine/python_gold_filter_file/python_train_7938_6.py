import sys,math
input=sys.stdin.readline
n, m, sx, sy = map(int,input().split())
sx -= 1
sy -= 1
mat = []
for i in range(n):
    temp = [0] * m
    mat.append(temp)
counter = 2
mat[sx][sy] = 1
for i in range(sy-1,-1,-1):
    mat[sx][i] = counter
    counter +=1
for i in range(sy+1,m):
    mat[sx][i] = counter
    counter +=1
toggle = 0
for i in range(sx-1,-1,-1):
    if toggle == 0:
        for j in range(m-1,-1,-1):
            mat[i][j] = counter
            counter += 1
        toggle =1
    else:
        for j in range(m):
            mat[i][j] = counter
            counter += 1
        toggle = 0
toggle2 = 1
if toggle == 1:
    toggle2 = 0
for i in range(sx+1,n):
    if toggle2 == 1:
        for j in range(m-1,-1,-1):
            mat[i][j] = counter
            counter += 1
        toggle2 = 0
    else:
        for j in range(m):
            mat[i][j] = counter
            counter += 1
        toggle2 = 1
l = []
for i in range(n):
    for j in range(m):
        l.append([mat[i][j], (i+1,j+1)])
l.sort(key = lambda x:x[0])
for i in l:
    print(i[1][0],i[1][1])