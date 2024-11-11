n,k,m,t=map(int,input().split())
for i in range(t):
    a,b=map(int,input().split())
    if a==1:
        if b<=k:
            k+=1
        n+=1
        print(n,k)
    else :
        if k>b:
            n=n-k+1
            k=1
        else :
            n=b
        print(n,k)
        