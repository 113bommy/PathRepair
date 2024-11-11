for _ in range(int(input())):
    n, a, b = map(int, input().split())
    print(max(a-b, n-a)+1)