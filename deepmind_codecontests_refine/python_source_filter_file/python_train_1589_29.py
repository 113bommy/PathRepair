for i in range(int(input())):
    x,y,n=map(int,input().split())
    if(n%x>=y):
        print(n-(n%x-y))
    else:
        print(n-n%x-y)