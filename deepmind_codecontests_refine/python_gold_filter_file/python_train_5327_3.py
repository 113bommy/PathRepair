for _ in range(int(input())):
    n,a,b=map(int,input().split())
    print(max(n-a,n-b)+1)