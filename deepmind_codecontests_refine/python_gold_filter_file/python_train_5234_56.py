for _ in range(int(input())):
    a,b=map(int,input().split())
    x=a%b
    if x!=0:
        print(b-x)
    else:
        print(x)