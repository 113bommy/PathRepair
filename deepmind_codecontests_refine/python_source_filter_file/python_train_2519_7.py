for _ in range(int(input())):
    a,b,n,s=map(int,input().split())
    if s%n<=b and s//n<=a:
        print("yes")
    else:
        print("no")