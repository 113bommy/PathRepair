n,k=map(int,input().split())
for i in range(1,n+1):
    if(n%i==0):
        r=n//k
        if(k>r):
            print(i*k+r)
            break