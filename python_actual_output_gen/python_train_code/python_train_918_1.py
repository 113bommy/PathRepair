for i in range(int(input())):
    n,m=map(int,input().split())
    if n==1 or m==1:
        print("YES")
    
    if n==2 and m==2:
        print("YES")
    else:
        print("NO")