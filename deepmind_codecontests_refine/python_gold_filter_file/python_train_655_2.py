for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    s=sum(arr)
    if s>=n:
        x=s%n 
        print(x*(n-x))
    else:
        print((n-s)*s)