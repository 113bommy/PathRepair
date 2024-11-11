for _ in range(int(input())):
    a,b=map(int,input().split())
    r=a%b
    if r!=0:
        print(b-r)
    else:
        print(0)