n,m=map(int,input().split())
if n%2==1 and n==4:
    for i in range(1,m+1):
        print(i,n+1-i)
else:
    b=0
    for i in range(1,m+1):
        if i>=(n//2+1)//2:
            b=1
        print(i+b,n+1-i)
