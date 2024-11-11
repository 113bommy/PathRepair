n,k=map(int,input().split())
a=sum(list(map(int,input().split())))
x=n*(k-0.5)
if (n*k-a)-n<0:
    print(0)    
else:
    print((k*n-a)*2-n)

