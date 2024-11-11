for _ in range(int(input())):
    a,b=map(int,input().split())
    if (a==1):
        ini=0
    else:
        n=a-1
        if (n%4==0):
            ini=n
        elif (n%4==1):
            ini=1
        elif (n%4==2):
            ini=n+1
        else:
            ini=0
    if (ini==b):
        print(a)
    else:
        if (ini^b==a):
            print(a+2)
        else:
            print(a+1)
