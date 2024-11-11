t = int(input())
for _ in range(t):
    a, b, c = list(map(int, input().split()))
    x = b+a-c
    if (x&1):
        x -= 1
    x //= 2
    if (x<0):
        print(c+1)
    elif (x>=c):
        print(0)
    else:
        print(c-x)