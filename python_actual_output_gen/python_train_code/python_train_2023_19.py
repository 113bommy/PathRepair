for _ in range(int(input())):
    a,b = map(int,input().split())
    if b>a:
        ans = (a*(a+1))//2 - (a-1)
    elif b==a:
        ans = (b*(b+1))//2 + 1

    else:
        ans = (b*(b+1))//2

    print(ans)