for i in range(int(input())):
    s, a, b, c=map(int,input().split())
    x=s//c
    y=x+((x*b)//a)
    print(y)