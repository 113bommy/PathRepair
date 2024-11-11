t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    zero = a.count(0)
    if (zero >= n//2):
        print(zero)
        print(*[0 for i in range(zero)])
    else:
        one = a.count(1)
        if (one % 2):
            print(one-1)
            print(*[1 for i in range(one-1)])
        else:
            print(one)
            print(*[1 for i in range(one - 1)])
