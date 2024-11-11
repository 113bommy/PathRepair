jj=int(input())
for j in range (jj):
    n,a,b=input().split(" ")
    n=int(n)
    a=int(a)
    b=int(b)
    price=0
    if ((2*a)<b):
        price=n*a
    else:
        if n%2==0:
            price=b*(n//2)
        else:
            price=b*((n//2))+a
    print (price)
        
