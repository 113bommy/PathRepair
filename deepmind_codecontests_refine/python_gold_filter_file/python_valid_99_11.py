for case in range(int(input())):
    n=int(input())
    s=list(input())
    firstType=list()
    secondType=list()
    ans=list([0]*n for i in range(n))
    flag=1

    for i in range(n):
        if s[i]=='1':
            firstType.append(i)
        else:
            secondType.append(i)
    for i in firstType:
        for j in range(n):
            if i==j:
                ans[i][j]='X'
            else:
                ans[i][j]='='
                ans[j][i]='='
    for i in secondType:
        f=0
        for j in range(n):
            if ans[i][j]=='+':
                f=j+1
                break
            elif i==j:
                ans[i][j]='X'
            elif ans[i][j]==0:
                ans[i][j]='+'
                ans[j][i]='-'
                f=j+1
                break
        if f!=0:
            for j in range(f,n):
                if i==j:
                    ans[i][j]='X'
                elif ans[i][j]==0:
                    ans[i][j]='-'
                    ans[j][i]='+'
        else:
            flag=0
    
    for i in range(n):
        if flag==0:
            break
        for j in range(n):
            if ans[i][j]=='0':
                flag=0
                break
    if flag:
        print('YES')
        for i in ans:
            print(*i,sep='')
    else:
        print('NO')      