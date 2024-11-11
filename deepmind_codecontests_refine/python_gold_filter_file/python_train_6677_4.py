for i in range(int(input())):
    n,a,b=map(int,input().split())
    if 2*a<=b:
        print(n*a)
    else:
        print(b*(n//2)+(n%2)*a)
