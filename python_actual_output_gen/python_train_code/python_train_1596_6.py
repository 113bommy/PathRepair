n=int(input())
for i in range(0,n):
    k=0
    a,b=map(int,input().split())
    if (a-b)!=1:
        k=1
    if a==b+1:
        x=2*b+1
        u=int(x**0.5)
        for i in range(2,u):
            if x%i==0:
                k=1
    if k==0:
        print('YES')
    else:
        print('NO')
