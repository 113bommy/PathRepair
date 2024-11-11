for _ in range(int(input())) :
    a=list(map(int,input().split()))
    b=sum(a)
    c=b/3
    if b%3==0 and c!=a[0] and c!=a[1] and c!=a[2] :
        print("YES")
    else :
        print("NO")