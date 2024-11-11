for _ in range(int(input())):
    n,a,b,c,d = map(int, input().split())
    if ((n*(a-b) <= c+d) and (a*(a-b) >= c-d)) or ((n*(a+b) <= c+d) and (a*(a+b) >= c-d)) or ((n*(a-b) <= c-d) and (a*(a+b) >= c+d)):
        print('YES')
    else:
        print('NO')