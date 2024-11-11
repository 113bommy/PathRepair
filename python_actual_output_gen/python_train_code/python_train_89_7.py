n=int(input())
if n>4:
    if n%2==1:
        print((n-2)*(n-1)*(n))
    else :
        if n%3!=0:
            print( (n-3)*(n-2)*(n-1))
        else:
            print( n*(n-1)*(n-3))
else :
    if n==3:
        print(6)
    elif n==4:
        print(12)
    elif n==2:
        print(2)
    elif n==1:
        print(1)