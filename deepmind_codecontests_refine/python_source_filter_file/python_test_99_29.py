t = int(input())

for i in range(t):
    x, n = map(int, input().split())
    if n % 4 == 0:
        print(x)
    else:
        if n % 4 == 1:
            if x % 2 == 1:
                print(x + n)
            else:
                print(x - n)
        elif n % 4 == 2:
            if n % 4 == 1:
                print(x - 1)
            else:
                print(x + 1)
        else:
            if x % 2 == 0:
                print(x + n + 1)
            else:
                print(x - n - 1)