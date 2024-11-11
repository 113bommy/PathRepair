for _ in " "*int(input()):
    a,b,c=map(int,input().split())
    if a==b==c:print("YES");print(a,b,c)
    elif a!=b and b!=c and c!=a:print("NO")
    elif a==b:
        if c>a:print("NO")
        else:print("YES");print(1,1,a)
    elif b==c:
        if a>b:print("NO")
        else:print("YES");print(1,1,b)
    elif a==c:
        if b>a:print("NO")
        else:print("YES");print(1,1,a)