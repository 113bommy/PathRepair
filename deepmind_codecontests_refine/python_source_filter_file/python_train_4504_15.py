for _ in range(int(input())):
    n,m=map(int,input().split())
    l=[0 for i in range(n)]
    for i in range(n):
        l[i]=list(map(int,input().split()))
    flag=True
    if l[0][0]>1 or l[n-1][0]>1 or l[0][m-1]>1 or l[n-1][m-1]>1:
        flag=False
    else:
        l[0][0]=1
        l[n-1][0]=1
        l[0][m-1]=1
        l[n-1][m-1]=1
    for i in range(1,m-1):
        if l[0][i]>3 or l[n-1][i]>3:
            flag=False
        else:
            l[0][i]=3
            l[n-1][i]=3
    
    for i in range(1,n-1):
        if l[i][0]>3 or l[i][m-1]>3:
            flag=False
        else:
            l[i][0]=3
            l[i][m-1]=3

    if flag:
        for i in range(1,n-1):
            if flag:
                for j in range(1,m-1):
                    if l[i][j]>4:
                        flag=False
                        break
                    else:
                        l[i][j]=4
    if flag:
        print("YES")
        for i in range(n):
            for j in range(m):
                print(l[i][j],end=" ")
            print()
    else:
        print("NO")

            


