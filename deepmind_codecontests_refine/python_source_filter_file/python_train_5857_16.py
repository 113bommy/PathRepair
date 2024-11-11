for i in range(int(input())):
    n, r = [int(i) for i in input().split()]
    if n>r:
        print((r*(r+1))//2)
    elif n == r:
        print((r*(r+1))//2 + 1)
    else:
        print((n*(n-1))//2 + 1)

