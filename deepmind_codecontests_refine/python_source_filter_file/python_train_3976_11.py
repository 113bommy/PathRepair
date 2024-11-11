for k in range(int(input())):
    s,i,n=map(int,input().split())
    if(n==0):
        if(s>i):
            print(1)
        else:
            print(0)
    else:
        print(min(n,max(0,n-(i+n-s)//2)))