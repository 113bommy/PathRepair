for i in range(int(input())):
    n=int(input())
    if(n%3==0):
        print(n//3,n//3)
    else:
        c1=n//3
        c2=n//3+1
        if(c1+2*c2==n):
            print(c1,c2)
        else:
            print(c2,c1)
