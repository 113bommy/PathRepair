t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    if a <= 2:
        print(a)
    else:
        a -= 2
        x, y = divmod(a, b)
        if y:
            print(x+2)
        else:
            print(x+1)