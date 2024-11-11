def answer(n,k):
    
    copy=k
    dp=[[0 for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(n):
            row=j
            col=(i+j)%n
            if k>0:
                dp[row][col]=1
                k-=1
            else:
                break
    l=[]
    for i in range(n):
        s=""
        for j in range(n):
            s+=str(dp[i][j])
        l.append(s)
    
   
    if copy==0 or (copy==n*n):
        return 0,l
    if copy>=n:
        if copy%n==0:
            return 0,l
        else:
            return 2,l
        
    if copy<n :
        return 2,l

          


t=int(input())
for x in range(t):
    n,k=map(int,input().split())
    a,b=answer(n,k)
    print(a)
    for i in b:
        print(i)