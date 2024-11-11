y=int(input())
for i in range(y):
    n,x,a,b=map(int,input().split())
    if(a==1 and b==n):
        print(b-a)
    elif(b==1 and a==n):
        print(a-b)
    elif(a>b):
        d=a-b+x
        if(d>=n):
            print(n-1)
        else:
            print(d)
    elif(b>a):
        d=b-a+x
        if(d>=n):
            print(n-1)
        else:
            print(d)
        