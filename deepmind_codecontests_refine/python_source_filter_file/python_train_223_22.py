for case in range(int(input())):
    a,b,t = map(int,input().split())
    if t==0:
        print(a)
    elif t==1:
        print(b)
    else:
        print(a^b)