n=int(input())
a=list(map(int,input().split(' ')))
if n==1:
    print(1,1)
    print(-a[0])
    print(1,1)
    print(0)
    print(1,1)
    print(0)
elif n==2:
    print(1,1)
    print(-a[0])
    print(2,2)
    print(-a[1])
    print(1,1)
    print(0)
else:
    print(1,1)
    print(-a[0])
    a[0]=0
    b=[]
    for i in range(1,len(a)):
        moda=a[i]%n
        c=moda*(n-1)
        b.append(c)
        a[i]+=c
    print(2,n)
    print(' '.join(list(map(str,b))))
    print(1,n)
    b=[]
    for i in a:
        b.append(-i)
    print(' '.join(list(map(str,b))))
