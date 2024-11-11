n = int(input())
if n > -1:
    print(n)
else:
    x = int(n / 100)*10 - (-n % 10)
    if int(n / 10) > x:
        print(-int(-n / 10))
    else:
        print(x)