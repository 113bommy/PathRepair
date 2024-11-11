import sys

input = sys.stdin.readline

for _ in range(int(input())):
    n,m = map(int,input().split())
    a = [input() for i in range(n)]
    a = [[a[i][j] for j in range(m)] for i in range(n)]

    res = []

    for x in range(0,n,2):
        for y in range(0,m,2):
            if x<n-1:
                if y<m-1:
                    i,j = x,y
                else:
                    i,j = x,y-1
            else:
                if y<m-1:
                    i,j = x-1,y
                else:
                    i,j = x-1,y-1
            tmp = int(a[i][j]) + int(a[i+1][j]) + int(a[i][j+1]) + int(a[i+1][j+1])
            if tmp==1:
                if a[i][j] == "1":
                    res.append((i,j,i,j))
                    res.append((i+1,j,i,j))
                    res.append((i,j+1,i,j))
                elif a[i+1][j] == "1":
                    res.append((i+1,j,i,j))
                    res.append((i,j,i,j))
                    res.append((i+1,j+1,i,j))
                elif a[i][j+1] == "1":
                    res.append((i,j+1,i,j))
                    res.append((i,j,i,j))
                    res.append((i+1,j+1,i,j))
                elif a[i+1][j+1] == "1":
                    res.append((i+1,j+1,i,j))
                    res.append((i+1,j,i,j))
                    res.append((i,j+1,i,j))
            elif tmp==2:
                if a[i][j]=="1" and a[i+1][j]=="1":
                    res.append((i,j+1,i,j))
                    res.append((i+1,j+1,i,j))
                elif a[i][j]=="1" and a[i][j+1]=="1":
                    res.append((i+1,j,i,j))
                    res.append((i+1,j+1,i,j))
                elif a[i][j]=="1" and a[i+1][j+1]=="1":
                    res.append((i,j,i,j))
                    res.append((i+1,j+1,i,j))
                elif a[i+1][j]=="1" and a[i][j+1]=="1":
                    res.append((i+1,j,i,j))
                    res.append((i,j+1,i,j))
                elif a[i+1][j]=="1" and a[i+1][j+1]=="1":
                    res.append((i,j,i,j))
                    res.append((i,j+1,i,j))
                elif a[i][j+1]=="1" and a[i+1][j+1]=="1":
                    res.append((i,j,i,j))
                    res.append((i+1,j,i,j))
            elif tmp==3:
                if a[i][j]=="0":
                    res.append((i+1,j+1,i,j))
                elif a[i+1][j]=="0":
                    res.append((i,j+1,i,j))
                elif a[i][j+1]=="0":
                    res.append((i+1,j,i,j))
                else:
                    res.append((i,j,i,j))
            elif tmp==4:
                res.append((i,j,i,j))
                res.append((i+1,j,i,j))
                res.append((i,j+1,i,j))
                res.append((i+1,j+1,i,j))

            a[i][j],a[i+1][j],a[i][j+1],a[i+1][j+1]="0","0","0","0"




    print(len(res))
    assert len(res)<=3*n*m
    for x,y,bx,by in res:
        #print(x,y,bx,by)
        tmp = []
        d_x = bx + (1-((x-bx)%2))
        d_y = by + (1-((y-by)%2))
        for i in range(2):
            for j in range(2):
                if bx+i!=d_x or by+j!=d_y:
                    tmp.append(bx+i+1)
                    tmp.append(by+j+1)
        print(*tmp)
