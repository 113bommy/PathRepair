q = int(input())
for _ in range(q):
    n = int(input())
    if n<4:
        print(-1)
    elif n==5:
        print(-1)
    elif n==7:
        print(-1)
    elif n==11:
        print(-1)
    else:
        if n%2==0:
            print(n//4)
        else:
            print((n-9)//4+1)
    