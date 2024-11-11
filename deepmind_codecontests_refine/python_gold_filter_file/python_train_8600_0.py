q = int(input())
for i in range(q):
    n = int(input())
    if n % 2 == 0:
        if n != 2:
            print(n // 4)
        else:
            print(-1)
    else:
        if n < 9 or n == 11:
            print(-1)
        else:
            print(1 + (n-9) // 4)
        
