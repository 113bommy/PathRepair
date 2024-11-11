for _ in range(int(input())):
    n = int(input())
    if n%2==0:
        if n==2:
            print(-1)
        else:
            print(n//4)
    else:
        if n<9 or n==11:
            print(-1)
        else:
            print(n-9//4)