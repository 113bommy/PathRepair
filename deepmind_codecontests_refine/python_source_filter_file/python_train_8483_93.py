n,m=map(int,input().split())

if n==m:
    print(n)
elif n>m:
    print(m,int((n-m)/2))
elif m>n:
    
    print(n,int((m-n)/2))
    