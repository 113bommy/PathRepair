for _ in range(int(input())):
    a,b=map(int,input().split())
    c=a%b
    if c==0:
        print(0)
    else:
        print(b-c)