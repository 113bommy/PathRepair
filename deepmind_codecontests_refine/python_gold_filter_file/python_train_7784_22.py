n,m=list(map(int,input().split()))
if n%2==0:
    for i in range(1,(m+1)//2+1):
        print(i+n//2,n-i+1)
    for i in range(1,m//2+1):
        print(i+1,n//2+1-i)
else:
    for i in range(1,m+1):
        print(i,n-i)
