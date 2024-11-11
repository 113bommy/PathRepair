for _ in " "*int(input()):
    n,m=map(int,input().split())
    n-=2
    if(n<1):
        print(1)
    elif(n%m==0):
        print((n-2)//m+1)
    else:
        print(((n-2)//m)+2)