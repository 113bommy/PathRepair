def nod(a,b):
    while a*b!=0:
        if a>b:
            a%=b
        else:
            b%=a
    return a+b
n,m,k=map(int,input().split())
if 2*n*m%k!=0:
    print('NO')
else:
    flag=0
    print('YES')
    if k%2==0:
        k//=2
        flag=1
    g=nod(n,k)
    ks=k//g
    a=n//g
    b=m//ks
    if flag:
        if a<n:
            a*=2
        else:
            b*=2
    print(0,0)
    print(a,0)
    print(0,b)
    
