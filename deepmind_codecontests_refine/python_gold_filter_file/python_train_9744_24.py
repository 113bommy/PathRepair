n,k=map(int,input().split())
a=sum(list(map(int,input().split())))
x=n*(k-0.5)
if 2*(n*k-a)-n<0:
    print(0)    
else:
    print(2*(k*n-a)-n)

