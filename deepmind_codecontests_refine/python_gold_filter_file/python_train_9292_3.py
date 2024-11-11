t=1
for test in range(t):
    n,d,m=map(int,input().split())
    arr=list(map(int,input().split()))
    big=[each for each in arr if each>m]
    small=[each for each in arr if each<=m]
    big=[0]+sorted(big,reverse=True)
    small=[0]+sorted(small,reverse=True)
    #print(big)
    for i in range(1,len(big)):
        big[i]+=big[i-1]
    for i in range(1,len(small)):
        small[i]+=small[i-1]
    ans=small[-1]
    for i in range(1,len(big)):
        days=(i-1)*(d+1)+1
        if days<=n:
            ans=max(ans,big[i]+small[min(len(small)-1,n-days)])
    print(ans)
