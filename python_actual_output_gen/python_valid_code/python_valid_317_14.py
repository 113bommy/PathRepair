for _ in range(int(input())):
    n, m = map(int, input().split())
    print((n*m)//2 + (1 if n % 2 == 1 else 0))