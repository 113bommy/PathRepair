for _ in range(int(input())):
    n = int(input())
    print(*([-1] if n < 4 else (([i for i in range(n - (n % 2 == 0), 0, -2)] + [4, 2] + [i for i in range(4, n, 2)]))))