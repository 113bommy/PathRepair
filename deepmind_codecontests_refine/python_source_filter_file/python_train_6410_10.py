n , m, k, x, y = map(int, input().split())
if(n==1):
    if(k%m == 0):
        print(k//m, k//m, k//m)
    if(k%m+1<y):
        print(k//m+1, k//m, k//m)
    else:
        print(k//m+1, k//m, k//m+1)
else:
    maxx = 2*(k//(2*(n-1)*m))
    minx = k//(2*(n-1)*m)

    k = k%(2*(n-1)*m)
    sinkr = x==n or x==1
    field = list()
    field.append([minx for i in range(m)])
    for i in range(n-2):
        field.append([maxx for i in range(m)])
    field.append([minx for i in range(m)])
    if(k<=n*m):
        b = k
        #print(field)
        while(k!=0):
            aa = n*m-k
            field[(b-k)//m][(b-k)%m]+=1
            k-=1
    else:
        #print('here')
        k -=n*m
        for i in range(n):
            for j in range(m):
                field[i][j]+=1;
        b = k

        while(k!=0):
            aa = (n-2)*m-k
            field[n-2-(b-k)//m][(b-k)%m]+=1
            k-=1
    #print(field)
    print(max(max(*field)), min(min(*field)), field[x-1][y-1])