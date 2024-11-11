t=int(input())
for i in range(t):
    n,x=map(int,input().split())
    if n<=2:
        print(1)
    else:
        if (n-2)%x==0:
            print(1+(n-2)//x)
        else:
            print(1+(n-2)//x+1)