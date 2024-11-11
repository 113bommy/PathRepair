for i in range(int(input())):
    n=int(input())
    if n<=30:
        print("NO")
    else:
        print("YES")
        if n-30 not in [6,10,14]:
            print(*[6,10,14,n-30])
        else:print(*[6,10,15,n-31])