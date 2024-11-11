for i in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    s=sum(a)
    if(s%2==0):
        print(s//n)
    else:
        print((s+1)//n)