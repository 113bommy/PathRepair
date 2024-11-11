n,p=map(int, input().split())
a=list(map(int, input().split()))
total=sum( i%2 for i in a )

if total==0:
    if p==0:
        print(2**n)
    else:
        print(0)
else:
    print(2**(n-1))