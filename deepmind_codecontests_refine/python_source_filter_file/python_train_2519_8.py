for _ in range(int(input())):
    a,b,n,s=map(int,input().split())
    if a*n+b>=s and (s)%a==0:
        print("yes")
    else:
        print("no")