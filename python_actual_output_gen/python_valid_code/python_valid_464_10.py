t = int(input())
for k in range(t):
    x, n = map(int, input().split())
    if x % 2 == 0:
        if n % 4 == 1:
            x = x - n
        elif n % 4 == 2:
            x = x + 1
        elif n % 4 == 3:
            x = x + n
    else:
        if n % 4 == 1:
            x = x + n
        elif n % 4 == 2:
            x = x - 1
        elif n % 4 == 3:
            x = x - n        
    print(x)