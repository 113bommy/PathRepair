for i in range(1):
    n,m,k=map(int,input().split())
    s=abs(m+k)%n
    if s==0:
        print(n)
    else:
        print(s)
