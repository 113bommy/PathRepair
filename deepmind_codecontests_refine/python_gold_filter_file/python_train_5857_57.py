for _ in range(int(input())):
    n,r=map(int,input().split())
    if(n>r):
        a=(r*(r+1))//2
        print(int(a))
    else:
        a=(n*n -(n-2))//2
        print(int(a))