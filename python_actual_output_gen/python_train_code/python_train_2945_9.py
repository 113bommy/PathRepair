for _ in range(int(input())):
    n,a,b = map(int,input().split())
    ans = "NO"
    for i in range(a+1):
        num = n
        for j in range(i):
            num = num/2 + 10
        for j in range(b):
            num -= 10
        if num <= 0:
            ans = "YES"
    print(ans)