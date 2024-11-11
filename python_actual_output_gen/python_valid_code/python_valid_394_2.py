t = int(input())
for i in range(t):
    n, x = list(map(int, input().split()))
    num = list(map(int, input().split()))
    if x in num:
        print(1)
        exit(0)
    ma = max(num)
    if ma > x:
        print(2)
    else:
        print((x + ma - 1) // ma)
