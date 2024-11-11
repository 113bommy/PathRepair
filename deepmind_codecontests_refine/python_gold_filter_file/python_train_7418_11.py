t = int(input())
for _ in range(t):
    n = int(input())
    if n <= 30:
        print("NO")
    else:
        print("YES")
        if n == 36:
            print("5 6 10 15")
        elif n == 40:
            print("5 6 14 15")
        elif n == 44:
            print("6 10 15 13")
        else:
            x = n-30
            print("6 10 14", x)
