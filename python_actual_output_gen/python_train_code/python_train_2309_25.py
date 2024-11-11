for _ in range(int(input())):
    n,a,b=map(int,input().split())
    if(n==1):
        print(a)
    elif(a>b):
        print((n//b)*b+(n%b)*a)
    else:
        print(n*a)