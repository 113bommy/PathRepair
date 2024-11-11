for _ in range(int(input())):
    n,k=map(int,input().split())
    a=k//n
    b=k%n
    if b==0:
        print(0)
    else:
        print(2)
    ans=[[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(a+int(b>0)):
            mod=(i+j)%n
            ans[i][mod]=1
        if b!=0:
            b-=1
    for i in range(n):
        for j in range(n):
            ans[i][j]=str(ans[i][j])
    
    for x in ans:
        print(''.join(x))