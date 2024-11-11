for _ in range(int(input())):
    n,m,k = map(int,input().split())
    check = False
    if n%2==1:
        k-=m//2
        if k%2==0 and k>=0:
            check = True
    elif m%2==0:
        if k%2==0 and k<=(n*m)//2-n//2:
            check = True
    else:
        if k%2==0:
            check = True
    if check:
        print("YES")
    else:
        print("NO")