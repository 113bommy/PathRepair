for _ in range(int(input())):
    n = int(input())
    if n==1 or n==2 or n==4:
        print(-1)
    else:
        if n%3==0:
            print(n//3,0,0)
        elif n%5==0:
            print(0,n//5,0)
        elif n%7==0:
            print(0,0,n//7)
        elif (n-7)%3==0:
            print((n-7)//3,0,1)
        elif (n-8)%3==0:
            print((n-8)//3+1,1,0)
        else:
            print(-1)