for i in range(int(input())):
    a,b=map(int,input().split())
    print(min(min(2*a,b),min(2*b,a))**2)
