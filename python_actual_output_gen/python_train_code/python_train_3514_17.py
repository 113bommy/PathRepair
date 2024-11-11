n = int(input())
while n > 0:
    n = n - 1
    a, b = [int(x) for x in input().split()]
    c = [int(x) for x in input().split()]
    if 2*b < min(c):
        print(-1)
    else:
        print(min(c)+b)