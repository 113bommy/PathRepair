n=int(input())
if n==1 or n==2:
    print('No')
else:
    a=[x for x in range(1,n+1)]
    ind=a.index(n-1)
    del a[ind]
    print('Yes')
    print(1,n-1)
    print(n-1,*a)
