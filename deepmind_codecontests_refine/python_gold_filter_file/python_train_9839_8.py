t = int(input())

ans = []
for i in range(t):
    n = int(input())
    
    SUM = ((1 + n)*n)//2

    for i in range(35):
        if 2**i <= n:
            SUM -= 2*(2**i)

    print(SUM)
