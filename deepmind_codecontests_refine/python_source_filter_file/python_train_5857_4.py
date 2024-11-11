for _ in range(int(input())):
    n, r = map(int,input().split())
    if n <= r:
        ans = (n * (n - 1) + 2) // 2
    else:
        ans = (n * (n + 1)) // 2
    
    print(ans)    