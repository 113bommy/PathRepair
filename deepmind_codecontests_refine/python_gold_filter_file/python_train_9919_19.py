for _ in range(int(input())):
    n, x = list(map(int, input().split()))
    print(max((n-3)//x + 2, 1))