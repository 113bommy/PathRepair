n=int(input())
if(n<=2):
    print (n)
else:
    if(n%2==1):
        print (n*(n-1)*(n-2))
    else:
        if(n%3==0):
            print ((n*(n-1)*(n-2))//2)
        else:
            print (n*(n-1)*(n-3))