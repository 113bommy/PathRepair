for i1 in range(int(input())):
    n,m=map(int,input().split())
    rows=[]
    columns=[]
    arr=[]
    for i in range(n):
        l=list(map(int,input().split()))
        arr.append(l)
    for i in range(n):
        for j in range(m):
            if arr[i][j]==1:
                rows.append(i)
                columns.append(j)
    
    rows=list(set(rows))
    columns=list(set(columns))
    r=len(rows)
    c=len(columns)
    ans=min(r,c)
    if ans%2==0:
        print('Vivek')
    else:
        print('Ashish')
    
                