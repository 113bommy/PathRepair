while(1):
    s,d=[int(x) for x in input().split()]
    A=[999 for x in range(d)]
    if s==0:    break
    for j in range(s):
        l=[int(x) for x in input().split()]
        for i in range(d):
            if l[i]!=0:
                A[i]=min(A[i], l[i]) 
    B=[[999 for x in range(d)] for y in range(d)]
    for j in range(d-1):
        l=[int(x) for x in input().split()]
        for i in range(d-1-j):
            if l[i]!=0:
                B[i][i+j+1]=l[i]
                B[i+j+1][i]=l[i]
    notevaled=[1 for x in range(d)]
    ans=0
    for i in range(d):
        mini=A.index(min(A))
        ans+=A[mini]
        notevaled[mini]=0
        A[mini]=999
        for x in range(d):
            if notevaled[x]:
                A[x]=min( A[x], B[mini][x] )
    print(ans)
        
