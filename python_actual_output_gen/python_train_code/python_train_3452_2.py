t = int(input())
for tt in range(t):
    n, m = list(map(int, input().split()))
    # arr = list(map(int, input().split()))
    # print(fun(arr, n, k))
    if(m % 2 == 1):
        print("NO")
        for i in range(n):
            a, b = list(map(int, input().split()))
            c, d = list(map(int, input().split()))
    else:
        f = 0
        for i in range(n):
            a, b = list(map(int, input().split()))
            c, d = list(map(int, input().split()))
            if(a == d):
                f = 1
        if(f == 0):
            print("NO")
        else:
            print("YES")